#include<bits/stdc++.h>
#define mod 998244353
#define INF 1000000000000000
using namespace std;
const int maxn=5e6+5;
int n,m,k;
int a[15][100005];
int c[maxn],f[maxn],ls[maxn];
long long ans,ans1;
struct node{int u,v,w;}e[maxn];
int read()
{
    int u=0,v=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') v=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        u=(u<<3)+(u<<1)+(ch^48);
        ch=getchar();
    }
    return u*v;
}
void print(int x)
{
    if(x<0) x=-x,putchar('-');
    if(x<10) putchar(x+48);
    else print(x/10),putchar(x%10+48);
}
int find(int x)
{
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
bool cmp(node x,node y){return x.w<y.w;}
inline void kruscal()
{
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        //if(cnt>=nn-1) break;
        int fx=find(e[i].u);
        int fy=find(e[i].v);
        if(fx!=fy) f[fx]=fy,ans1+=e[i].w/*,cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n"*/;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    bool f11=1;
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)
        e[i].u=read(),e[i].v=read(),e[i].w=read();
    for(int i=1;i<=k;i++)
    {
        c[i]=read();
        if(c[i]!=0) f11=0;
        bool f1=0;
        for(int j=1;j<=n;j++)
        {
            a[i][j]=read();
            if(a[i][j]==0) f1=1;
        }
        if(!f1) f11=0;
    }
    if(k==0)
    {
        for(int i=1;i<=n;i++)
            f[i]=i;
        kruscal();
        cout<<ans1;
    }
    else if(f11)
    {
        for(int i=1;i<=n;i++)
            f[i]=i;
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
                if(a[i][j]==0)
                {
                    if(ls[i]) f[j]=ls[i];
                    else ls[i]=j;
                }
        }
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
                if(a[i][j]!=0)
                {
                    e[++m].u=ls[i];
                    e[m].v=j;
                    e[m].w=a[i][j];
                }
        }
        kruscal();
        cout<<ans1;
    }
    else
    {
        //cout<<"qwq\n";
        int m1=m;
        ans=INF;
        for(int i=0;i<(1<<k);i++)
        {
            m=m1;
            ans1=0;
            for(int ii=1;ii<=k+n;ii++)
                f[ii]=ii;
            for(int j=1;j<=k;j++)
                if((1<<(j-1))&i)
                {
                    ans1+=c[j];
                    for(int j1=1;j1<=n;j1++)
                    {
                        e[++m].u=j1;
                        e[m].v=n+j;
                        e[m].w=a[j][j1];
                    }
                }
            kruscal();
            //cout<<"----------"<<i<<" "<<ans1<<"\n";
            ans=min(ans,ans1);
        }
        cout<<ans;
    }
    return 0;
}
