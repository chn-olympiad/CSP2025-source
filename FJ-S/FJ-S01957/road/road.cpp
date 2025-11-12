#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
  {int w=0,f=1;
  char ch=getchar();
  for(;ch<'0'||ch>'9';ch=getchar())  if(ch=='-')  f=-1;
  for(;ch>='0'&&ch<='9';ch=getchar())  w=(w<<3)+(w<<1)+(ch^48);
  return w*f;
  }
const int N=1e4+10,M=1e6+10;
//bool ed;
int n,m,fa[N],k;
ll ans,t[15][N];
bool f;
inline int find(int x)
  {if(x!=fa[x])  return fa[x]=find(fa[x]);
  return fa[x];
  }
struct xx
  {int x,y;ll z;
  bool operator<(const xx&h)const
    {return z<h.z;
	}
  }b[M+100010];
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
scanf("%d%d%d",&n,&m,&k);
for(int i=1;i<=n;i++)  fa[i]=i;
for(int i=1;i<=m;i++)  
  b[i].x=read(),b[i].y=read(),b[i].z=read();
for(int i=1;i<=k;i++)  
  {t[i][0]=read();
  for(int j=1;j<=n;j++)  t[i][j]=read();
  f|=!t[i][0];
  }
if(k==0)
  {sort(b+1,b+1+m);
  for(int i=1;i<=m;i++)
    {int fx=find(b[i].x),fy=find(b[i].y);
	if(fx!=fy)  ans+=b[i].z,fa[fx]=fy;
	}
  printf("%lld\n",ans);
  return 0;
  }
if(f)
  {for(int i=1;i<=k;i++)
    {for(int j=1;j<=n;j++)
      if(t[i][j]==0)  
        {for(int s=1;s<=m;s++)
          if(b[s].x==j)  b[s].z=min((ll)t[i][b[s].y],b[s].z);
          else  if(b[s].x==j)  b[s].z=min((ll)t[i][b[s].y],b[s].z);
		}
	}
  sort(b+1,b+1+m);
  for(int i=1;i<=m;i++)
    {int fx=find(b[i].x),fy=find(b[i].y);
    if(fx!=fy)  ans+=b[i].z,fa[fx]=fy;
    }
  printf("%lld\n",ans);
  }
//bool st;
//printf("%d",(&st-&ed)/(1<<20));
}

