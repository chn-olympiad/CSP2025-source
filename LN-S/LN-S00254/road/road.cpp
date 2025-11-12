#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+15,M=1e6+10;
const int NM=M+2*N;
int n,m,k;
int e[N][N];
int d[N][N];
struct node{
    int I,J,val;
}edge[N*N/2];
void floyd()
{
    for(int p=1;p<=n;p++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j:e[p])
            {
                d[i][j]=min(d[i][j],d[i][k]+e[k][j]);
            }
        }
    }
}
bool cmp(node a,node b)
{
    return a.val<b.val;
}
int ans;
bool init[N];
int sum; 
int u,v,w;
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
    memset(e,0x3f,sizeof(e));
    for(int i=1;i<=m;i++)
    {
       
        scanf("%d%d%d",&u,&v,&w);
        e[u][v]=min(e[u][v],w);
        e[v][u]=min(e[v][u],w);
    }
    for(int j=1;j<=k;j++)
    {
        int c,a;
        cin>>c;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            e[j+n][i]=a;
            e[i][j+n]=a+c;
        }
    }
    for(int i=1;i<=n+k;i++) e[i][i]=0;
    floyd();
    int idx=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
             edge[++idx]={i,j,d[i][j]};
            
        }
       
    }
    sort(edge+1,edge+idx+1,cmp);

    for(int i=1;i<=idx;i++)
     {
         if(i==1)
         {
             ans+=edge[i].val;
             init[edge[i].I]=1;
             init[edge[i].J]=1;
            sum+=2;
         }
         if(init[edge[i].I]
             && init[edge[i].J]) continue;
        ans+=edge[i].val;
        if(!init[edge[i].I]) sum++,init[edge[i].I]=1;
        if(!init[edge[i].J]) sum++,init[edge[i].J]=1;

        if(sum==n) break;
     }

     printf("%d",ans);
   fclose(stdin);fclose(stdout);
    return 0;
}