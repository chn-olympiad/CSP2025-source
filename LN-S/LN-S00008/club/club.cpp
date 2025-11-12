#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
struct edge
{
    int manyidu,idx;
};
bool cmp(edge e1,edge e2)
{
    return e1.manyidu>e2.manyidu;
}
struct node
{
    edge ai[4];
}a[N];
bool cmp1(node a1,node a2)
{
    if(a1.ai[1].manyidu!=a2.ai[1].manyidu)return a1.ai[1].manyidu>a2.ai[1].manyidu;
    else
    {
        if(a1.ai[2].manyidu!=a2.ai[2].manyidu)return a1.ai[2].manyidu>a2.ai[2].manyidu;
        else
        {
            return a1.ai[3].manyidu>a2.ai[3].manyidu;
        }
    }
}
bool cmp2(node a1,node a2)
{
    return a1.ai[1].manyidu-a1.ai[2].manyidu<a2.ai[1].manyidu-a2.ai[2].manyidu;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    long long ans=0;
    while(T--)
    {
        ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].ai[1].manyidu>>a[i].ai[2].manyidu>>a[i].ai[3].manyidu;
            a[i].ai[1].idx=1,a[i].ai[2].idx=2,a[i].ai[3].idx=3;
            sort(a[i].ai+1,a[i].ai+4,cmp);
        }
        sort(a+1,a+n+1,cmp1);
        vector<node>nu[4];
        int x[4];
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++)
        {
            nu[a[i].ai[1].idx].push_back(a[i]);
            x[a[i].ai[1].idx]+=a[i].ai[1].manyidu;
        }
        int y=0;
        for(int i=1;i<=3;i++)
        {
            if(nu[i].size()>n/2)y=i;
            ans+=x[i];
        }
        if(y==0)
        {
            cout<<ans<<"\n";
            continue;
        }
        sort(nu[y].begin(),nu[y].end(),cmp2);
        for(int i=0;i<nu[y].size()-n/2;i++)
        {
            ans-=nu[y][i].ai[1].manyidu;
            ans+=nu[y][i].ai[2].manyidu;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
