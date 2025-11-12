#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>

//#include<iostream>

#define N 10010
#define M 1000010
#define K 22
#define LL long long
//#define int long long
using namespace std;
inline int read()
{ char ch=getchar();int p=0;
  for(;ch<'0'||'9'<ch;ch=getchar());
  for(;'0'<=ch&&ch<='9';p=(p<<3)+(p<<1)+ch-'0',ch=getchar());
  return p;
}
inline void print(const LL &x)
{ if(x<0) { putchar('-'),print(-x); return; }
  if(x<10) { putchar(x+'0'); return; }
  print(x/10),putchar(x%10+'0');
}
struct WAY
{ int x,y,z;
}w[M],wc[N<<1],wp[N<<1],wq[N<<1];
inline bool cmp(const WAY &A,const WAY &B)
{ return A.z<B.z;
}
int fa[N<<1];
inline int find(const int &x)
{ return fa[x]=(x==fa[x]?x:find(fa[x]));
}
inline LL gettree(const int &n,const int &m)
{ for(int i=1;i<=n;i++) fa[i]=i;
  sort(w+1,w+m+1,cmp);
  int num=0;
  LL ans=0;
  for(int i=1;i<=m;i++)
	{ int x=w[i].x,y=w[i].y,z=w[i].z;
	  int r1=find(x),r2=find(y);
	  if(r1==r2) continue;
	  fa[r2]=r1;
	  wc[++num]={x,y,z},ans+=z;
	  if(num==n-1) break;
	}
  
//  cerr<<ans<<endl;
  
  return ans;
}
int c[K],a[K][N],s[K],r[K];
inline LL solve(const int &n,const int &x)
{ 
//  cerr<<"work on "<<x<<endl;
  
  int m=n-1+x-1;
  for(int i=1;i<=m;i++) wp[i]=w[i];
  for(int i=1;i<=n;i++) w[++m]={n+x,i,a[x][i]};
  
//  cerr<<"edge:"<<endl;
//  for(int i=1;i<=m;i++)
//	{ cerr<<'('<<w[i].x<<',';
//	  cerr<<w[i].y<<',';
//	  cerr<<w[i].z<<')'<<endl;
//	}
  
  LL ans=gettree(n+x,m);
  for(int i=1;i<=x;i++) s[i]=r[i]=0;
  for(int i=1;i<=n-1+x;i++)
	{ int x=wc[i].x,y=wc[i].y,z=wc[i].z;
	  if(x>n) s[x-n]=z,r[x-n]++;
	  if(y>n) s[y-n]=z,r[y-n]++;
	}
  for(int i=1;i<=x;i++)
	if(r[i]==1) ans-=s[i];
	else ans+=c[i];
  
//  cerr<<"ans="<<ans<<endl;
  
  return ans;
}
inline void update(const int &n,const int &x,const bool &f)
{ if(!f)
	{ for(int i=1;i<=n-1+x-1;i++) w[i]=wp[i];
	  w[n-1+x]={n+x,1,a[x][1]};
	}
  else
	{ for(int i=1;i<=n-1+x;i++) w[i]=wc[i];
	}
}
inline LL getans(const int &n,const int &k,const LL &v)
{ LL ans=v;
  for(int i=1;i<=k;i++)
	{ LL Ans=solve(n,i);
	  update(n,i,Ans<ans);
	  ans=min(Ans,ans);
	}
  return ans;
}
inline int rd(const int &l,const int &r)
{ return rand()%(r-l+1)+l;
}
const LL inf=1e18;
const int B=6;
const int YY=10;
signed main()
{ freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  int n=read(),m=read(),k=read();
  for(int i=1;i<=m;i++)
	{ int x=read(),y=read(),z=read();
	  w[i]={x,y,z};
	}
  LL J=gettree(n,m);
  for(int i=1;i<n;i++) w[i]=wc[i];
  for(int i=1;i<n;i++) 
  wq[i]=w[i];
  for(int i=1;i<=k;i++)
	{ c[i]=read();
	  for(int j=1;j<=n;j++) a[i][j]=read();
	}
  srand(time(0));
  LL ans=getans(n,k,J);
//  LL ans=inf;
  for(int i=1;i<=B;i++)
	{ for(int j=1;j<n;j++) w[j]=wq[j];
	  for(int j=1;j<=YY;j++)
		{ int x=rd(1,k),y=rd(1,k);
		  if(x==y) continue;
		  swap(c[x],c[y]);
		  for(int g=1;g<=n;g++)
			swap(a[x][g],a[y][g]);
		}
	  ans=min(ans,getans(n,k,J));
	}
  print(ans),putchar('\n');
}