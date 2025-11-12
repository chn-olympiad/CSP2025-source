#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int nummin;
vector <int> q[1000005];
vector <int> p[10006];
int ci[15];
struct code
{
    int pre,nxt,id;
}a[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1,o,p,e;i<=m;i++)
    {
        cin>>o>>p>>e;
        q[o].push_back(p);
        q[p].push_back(o);
        a[i].pre=o;
        a[i].nxt=p;
        a[i].id=e;

    }
    for (int i=1,c;i<=k;i++)
    {
        cin>>c;
        p[1].push_back(c);
        for (int j=2,a;j<=n+1;j++)
        {
            cin>>a;
            p[j].push_back(a);
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;i++)
        {
            int num=0;
            for (int w=1;w<=m;w++)
            {
                if (a[w].pre==i && a[w].nxt==j)
                    num=a[w].id;
            }
            int ans=0,minn=1e8,r1=0;
            for (int r=1;r<=k;r++)
            {
                minn=1e8;
                if (ci[r]==1)
                    ans=0;
                else ans=p[1][r];
                ans+=p[i][r]+p[j][r];
                minn=(ans,minn);
                r1=r;
            }
            if (num<minn)
            {
                nummin+=num;
            }
            else if (minn<num)
            {
                ci[r1]=1;
                nummin+=minn;
            }
        }
    }
    cout<<nummin;
    return 0;
}
