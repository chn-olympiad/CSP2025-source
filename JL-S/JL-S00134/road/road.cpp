#include<bits/stdc++.h>
using namespace std;
int n,m,k,vill[15][10005],ljjz[10004][10004],fa[10004];
bool villuse[14];
long long sum=0;
struct Edge
{
    int dq,u,v,w;
}e[10005];
bool cmp(Edge x,Edge y)
{
    return x.w<y.w;
}
int findd(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=findd(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int uu,vv,ww;
    memset(ljjz,0x3f,sizeof(ljjz));
    for(int i=1;i<=n;i++)
    {
        ljjz[i][i]=0;
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>uu>>vv>>ww;
        ljjz[uu][vv]=ww;
        ljjz[vv][uu]=ww;


    }
    for(int i=1;i<=k;i++)
    {
        cin>>vill[i][0];
        for(int j=1;j<=n;j++)
        {
            cin>>vill[i][j];
        }

    }
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
                int usevil=0;
                for(int l=1;l<=k;l++)
                {
                    if(vill[l][i]+vill[l][j]<ljjz[i][j])
                    {
                        //villuse[l]=1;
                        ljjz[i][j]=vill[l][i]+vill[l][j];
                        ljjz[j][i]=vill[l][i]+vill[l][j];
                        usevil=l;
                    }
                }
                if(ljjz[i][j]!=0x3f3f3f3f) e[++tot]={usevil,i,j,ljjz[i][j]};

        }
    }
    //krskr
    sort(e+1,e+tot+1,cmp);
    int edges=0;
    for(int i=1;i<=tot;i++)
    {
        int fu=findd(e[i].u),fv=findd(e[i].v);
        if(fu==fv) continue;
        fu=fa[fv];
        sum+=e[i].w;
        villuse[e[i].dq]=1;
        edges++;
        if(edges==n-1) break;
    }
    cout<<sum;
    return 0;
}
