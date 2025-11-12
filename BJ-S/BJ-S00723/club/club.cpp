#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10,M=2e2+110;
long long T,n,vis[N],b[M][4],f[M][M][M];
struct Node{
    long long num,to,v;
}a[N*3];
bool cmp(Node x,Node y)
{
    return x.v>y.v;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n<=210)
        {
            memset(f,0,sizeof(f));
            for(long long i=1;i<=n;i++)
            {
                cin>>b[i][1]>>b[i][2]>>b[i][3];
            }
            for(long long i=1;i<=n;i++)
            {
                for(long long j=0;j<=min(i,n/2);j++)
                {
                    for(long long k=0;k<=min(i-j,n/2);k++)
                    {
                        if((i-j-k)<=min(i,n/2))
                        {
                            if(j+1<=n/2)
                                f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+b[i][1]);
                            if(k+1<=n/2)
                                f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+b[i][2]);
                            if(i-j-k+1<=n/2)
                                f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+b[i][3]);
                        }
                    }
                }
            }
            long long ans=0;
            for(long long j=0;j<=n/2;j++)
            {
                for(long long k=0;k<=n/2;k++)
                {
                    if((n-j-k)<=n/2)
                    {
                        ans=max(ans,f[n+1][j][k]);
                    }
                }
            }
            cout<<ans<<"\n";
        }  
        else
        {
            long long j[4]={0,0,0,0},cnt=0;
            memset(vis,0,sizeof(vis));
            for(long long i=0;i<n;i++)
            {
                long long x,y,z;
                cin>>x>>y>>z;
                
                a[i*3+1]=(Node){i+1,1,x};
                a[i*3+2]=(Node){i+1,3,y};
                a[i*3+3]=(Node){i+1,2,z};
            }
            sort(a+1,a+1+n*3,cmp);
            for(long long i=1;i<=n;i++)
            {
                if(!vis[a[i].num]&&j[a[i].to]<n/2)
                {
                    vis[a[i].num]=1;
                    j[a[i].to]++;
                    cnt+=a[i].v;
                }
                a[i]=(Node){0,0,0};
            }
            cout<<cnt<<"\n";
        }
    }
    return 0;
}