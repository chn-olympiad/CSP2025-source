#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int M=1e4+5;
int n,m,k,t=0,sum=0,fa[M],c[15],a[15][M],dist[M],ans=0x3f3f3f3f;
struct Node{
    int u,v,w;
}se[N];
bool cmp(Node A,Node B)
{
    return A.w<B.w;
}
int find(int x)
{
    if(fa[x]==x)
        return x;
    int ff=fa[x];
    fa[x]=find(ff);
    return fa[x];
}
int main(void)
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>se[i].u>>se[i].v>>se[i].w;
        }
        for(int j=1;j<=k;j++)
        {
            cin>>c[j];
            for(int i=1;i<=n;i++)
            {
                cin>>a[j][i];
            }
        }
        sort(se+1,se+1+m,cmp);
            for(int i=1;i<=m;i++)
            {
                if(find(se[i].u)!=find(se[i].v))
                {
                    t++;
                    fa[se[i].u]=se[i].v;
                    sum+=se[i].w;
                }
                if(t==n-1)
                    break;
            }
        cout<<sum;
    }
    return 0;
}
