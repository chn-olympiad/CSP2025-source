#include<bits/stdc++.h>
using namespace std;
struct node{
    int first,second;
};
vector<node> v[3];
int temp[3];
bool cmp(node x,node y)
{
    return (x.first-x.second)<(y.first-y.second);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        vector<node> v[3];
        int vis[3]={0,0,0};
        int n,sum=0;cin>>n;
        for(int i=1;i<=n;i++)
        {
            int c1,c2,mx1=-1,mx2=-1;
            for(int j=0;j<3;j++)
            {
                cin>>temp[j];
                if(temp[j]>mx1)
                {
                    if(mx1>mx2)
                            mx2=mx1,c2=c1;
                    mx1=temp[j];
                    c1=j;
                    continue;
                }
                if(temp[j]>mx2)
                {
                    mx2=temp[j];
                    c2=j;continue;
                }
            }
            sum+=mx1;vis[c1]++;
            v[c1].push_back({mx1,mx2});
        }
        int num=0,cur=0;
        for(int i=0;i<3;i++)
            if(vis[i]>(n/2))
            {
                cur=i;num=vis[i]-(n/2);
            }
        if(num==0)
        {
            cout<<sum<<endl;
            continue;
        }
        sort(v[cur].begin(),v[cur].end(),cmp);
        for(int i=0;i<num;i++)
        {
           sum-=(v[cur][i].first-v[cur][i].second);
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
