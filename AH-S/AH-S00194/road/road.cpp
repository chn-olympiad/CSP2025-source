#include<bits/stdc++.h>
#define ll long long
#define N 1100005
#define pii pair<int,int>
#define swap(a,b) (a^=b^=a^=b)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define sqrt(a) __builtin_sqrt(a)
using namespace std;
int fa[10010],n,m,k,w[15],fl[15],d[15];
ll ans;
int find(int x){return (x==fa[x])?x:(fa[x]=find(fa[x]));}
struct Node{
    int u,v,w,pd;
}e[N];
void read(int &x)
{
    x=0;
    int f=1;
    char ch=getchar_unlocked();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=getchar_unlocked();
    }
    while(ch>=48&&ch<=57)
        x=x*10+(ch-'0'),ch=getchar_unlocked();
    x*=f;
}
bool cmp(Node a,Node b)
{
	return a.w<b.w;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n),read(m),read(k);
    for(int i=1;i<=n+k;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
        read(e[i].u),read(e[i].v),read(e[i].w);
    for(int i=1;i<=k;i++)
    {
        read(w[i]);
        for(int j=1;j<=n;j++)
            e[m+j+(i-1)*n].u=n+i,e[m+j+(i-1)*n].v=j,read(e[m+j+(i-1)*n].w),e[m+j+(i-1)*n].w+=w[i],e[m+j+(i-1)*n].pd=i;
    }
    int len=m+(k*n);
    sort(e+1,e+1+len,cmp);
    for(int i=1;i<=len;i++)
    {
        int x=find(e[i].u),y=find(e[i].v);
        if(x!=y)
        {
			fa[x]=y;
            ans+=e[i].w;
            n--;
			if(!fl[e[i].pd]&&e[i].pd)
				n++,d[e[i].pd]=e[i].w;
            if(fl[e[i].pd])
                ans-=w[e[i].pd];
            fl[e[i].pd]++;
        }
        if(n==1)
        {
            for(int i=1;i<=k;i++)
                if(fl[i]==1)
                    ans-=d[i];
			printf("%lld",ans);
			return 0;
		}
    }
    return 0;
}
