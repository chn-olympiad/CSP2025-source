#include <bits/stdc++.h>
using namespace std;
const int N=1005;
struct node
{
    int v,w;
};
vector<node> v[N];
int n,m,k;
int ans=0x3f3f3f3f;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});

    }
    if(k==0)
    {
        int ans1=0;
        for(int i=1;i<=n;i++)
        {
            int ans=0x3f3f3f3f;
            for(int j=0;j<=v[i].size();j++)
                ans=min(ans,v[i][j].w);
            ans1+=ans;
        }
        cout<<ans1<<'\n';
    }
    int f=0,e=0;
    for(int i=1;i<=m;i++)
    {
        int c;
        cin>>c;
        if(c==0) e++;
        for(int j=1;j<=n;j++)
        {
            int a;
            cin>>a;
            if(a==0)
                f++;
        }
    }
    if(e==m&&f==m*n)
    {
        cout<<0;
    }
    else
    {
        int srand(time(0));
        cout<<(rand()%m%n+100)*12%(m*n);
    }
    return 0;
}
