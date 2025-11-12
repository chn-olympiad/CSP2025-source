#include <bits/stdc++.h>
using namespace std;
struct Road
{
    int x1;
    int x2;
    int w;
}r[1000005],rn[1000005];
bool rule(Road r1,Road r2)
{
    return(r1.w<r2.w);
}
int n,m,k;
bool vis[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
        int cntro =0;
        for(int i=0;i<m;i++)
        {
            cin>>r[i].x1>>r[i].x2>>r[i].w;
            cntro++;
        }
        sort(r,r+cntro,rule);
        for(int i=0;i<k;i++)
        {
            int wi;
            cin>>wi;
            int tr[10005];
            for(int i=0;i<n;i++)
            {
                int ri;
                cin>>ri;
                if(ri>r[m-1].w)
                {
                    tr[i]=-1;
                    continue;
                }
                tr[i]=ri;
            }
            for(int i=0;i<n;i++)
            {
                if(tr[i]==-1)continue;
                for(int j=0;j<n;j++)
                {
                    int wa=tr[i]+tr[j]+wi;
                    if(tr[j]==-1||wa>r[m-1].w)continue;
                    r[cntro].x1=i;
                    r[cntro].x2=j;
                    r[cntro++].w=wa;
                }
            }
        }
        sort(r,r+cntro,rule);
        int cntl=0,cntr=0;
        for(int i=0;cntl<n;i++)
        {
            if(vis[r[i].x1]&&vis[r[i].x2])
                continue;
            rn[cntr++]=r[i];
            if(!vis[r[i].x1])
            {
                cntl++;
            }
            if(!vis[r[i].x2])
            {
                cntl++;
            }
        }
            int sum=0;
            for(int i=0;i<cntr;i++)
            {
                cout<<rn[i].w;
                sum+=rn[i].w;
            }

            cout<<sum;
    return 0;
}