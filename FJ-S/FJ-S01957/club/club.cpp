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
const int N=1e5+10;
int n,g[4];
int z[N],xs,v[N];
ll ans,xz[4];
bool f;
struct xx
  {ll x,id,g;
  bool operator<(const xx &z)const
    {return x<z.x;
	}
  };
struct yg
  {int s[4];
  bool operator<(const yg &z)const
    {
//	if(max(max(s[1],s[2]),s[3])!=max(max(z.s[1],z.s[2]),z.s[3]))
	return max(max(s[1],s[2]),s[3])>max(max(z.s[1],z.s[2]),z.s[3]); 
//	return max(max(s[1],s[2]),s[3])+min(min(s[1],s[2]),s[3])>max(max(z.s[1],z.s[2]),z.s[3])+min(min(z.s[1],z.s[2]),z.s[3]); 
//	return min(min(s[1],s[2]),s[3])<min(min(z.s[1],z.s[2]),z.s[3]);
//	return <;
//	return s[1]+s[2]+s[3]<z.s[1]+z.s[2]+z.s[3];
//	return >;
	}
  }a[N];
priority_queue<xx>q[4];
inline void solve(int i,int x)
  {if(xz[x]==a[i].s[x])  
	{g[x]++;
    ans+=xz[x];
//    v[i]=x;
	for(int j=1;j<=3;j++)  if(j!=x)  q[x].push((xx){-a[i].s[x]+a[i].s[j],i,j});
	}
  else
	{xx ab=q[x].top();
	q[x].pop();
	g[ab.g]++;
	ans+=xz[x];
	v[ab.id]=ab.g;
	for(int j=1;j<=3;j++)  if(j!=ab.g)  q[ab.g].push((xx){-a[ab.id].s[x]+a[ab.id].s[j],ab.id,j});
//	q[ab.g]
//	for(int j=1;j<=3;j++)  if(j!=x)  q[x].push((xx){-xz[x]+a[i].s[j],i,j});
	for(int j=1;j<=3;j++)  if(j!=x)  q[x].push((xx){-a[i].s[x]+a[i].s[j],i,j});
    }
  }
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
for(int T=read();T;T--)
  {scanf("%d",&n);
  memset(v,0,sizeof(v));
  memset(g,0,sizeof(g));
  for(int i=1;i<=3;i++)  while(!q[i].empty())  q[i].pop();
  xs=n/2;
  ans=0;
  f=1;
  for(int i=1;i<=n;i++)
    {for(int j=1;j<=3;j++)
      a[i].s[j]=read(),f&=(a[i].s[2]==0&&a[i].s[3]==0);
	}
  if(f==1)
    {for(int i=1;i<=n;i++)  z[i]=a[i].s[1];
    sort(z+1,z+1+n);
    for(int i=n;i>xs;i--)  ans+=z[i];
    printf("%lld\n",ans);
    continue;
	}
  sort(a+1,a+1+n);
  for(int i=1;i<=n;i++)
    {
    for(int j=1;j<=3;j++)
      {while(!q[j].empty()&&v[q[j].top().id])  q[j].pop();
	  if(q[j].empty()||g[j]<xs)  xz[j]=a[i].s[j];
	  else  xz[j]=a[i].s[j]+q[j].top().x;
	  }
	if(xz[1]>=xz[2]&&xz[1]>=xz[3])
	  solve(i,1);
	else  if(xz[2]>=xz[1]&&xz[2]>=xz[3])
	  solve(i,2);
	else  solve(i,3);
	}
  printf("%lld\n",ans);
  }
}
