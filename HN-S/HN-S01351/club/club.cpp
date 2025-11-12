#include<bits/stdc++.h>
using namespace std;
struct club{
    int satisfy;
    int id;
};
inline void solve()
{
    int n;
    scanf("%d",&n);
    vector<vector<club>>c(n+1,vector<club>(3));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&c[i][j].satisfy);
            c[i][j].id=j;
        }
        sort(c[i].begin(),c[i].end(),[&](const club &a,const club &b){
            return a.satisfy>b.satisfy;
        });
    }
    int sum=0;
    vector<vector<int>>id(3);
    for(int i=1;i<=n;i++)
    {
        sum+=c[i][0].satisfy;
        id[c[i][0].id].push_back(i);
    }
    int lim=n/2;
    bool valid=true;
    for(int t:{0,1,2})
        valid&=(id[t].size()<=lim);
    if(!valid)
    {
        int p=0;
        for(int t:{0,1,2})
            if(id[t].size()>lim)
                p=t;
        vector<int>diff;
        for(int u: id[p])
            diff.push_back(max(c[u][1].satisfy,c[u][2].satisfy)-c[u][0].satisfy);
        sort(diff.begin(),diff.end());
        while(diff.size()>lim)
        {
            sum+=diff.back();
            diff.pop_back();
        }
    }
    printf("%d\n",sum);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--)
        solve();

    return 0;
}