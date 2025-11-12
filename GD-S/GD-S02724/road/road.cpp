#include<bits/stdc++.h>
using namespace std;

#define int ll
#define pii pair<int,int>
#define ll long long

#define For(a,b,c) for(int a=(b);a<=(c);a++)
#define Rep(a,b,c) for(int a=(b);a>=(c);a--)

int read() {
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9'; ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9'; ch=getchar()) x=(x*10)+ch-'0';
	return x*f;
}

#define in1(a) a=read()
#define in2(a,b) a=read(),b=read()
#define in3(a,b,c) a=read(),b=read(),c=read()
#define in4(a,b,c,d) a=read(),b=read(),c=read(),d=read()

const int maxn=10014;

int n,m,k;

struct node {
	int u,v,d;
}a[1200000];
int top=0;

int c[11];

int fa[maxn];
int fnd(int x) {
	return fa[x]==x?fa[x]:fa[x]=fnd(fa[x]);
}

bool vis[maxn];

bool cmp(node a,node b) {
	return a.d<b.d;
}

signed main() {
	int ans=1e18;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	in3(n,m,k); top=m;
	For(i,1,m) {
		int u,v,d; in3(u,v,d);
		a[i]={u,v,d};
	}
	For(i,1,k) {
		c[i]=read();
		For(x,1,n) {
			int val=read();
			a[++top]={n+i,x,val};
		}
	}
	sort(a+1,a+top+1,cmp);
	For(S,0,(1<<k)-1) {
		For(i,1,n+k) vis[i]=0;
		For(i,1,n+k) fa[i]=i; 
		int res=0;
		For(i,1,k) if(S&(1<<(i-1))) res+=c[i]; else vis[n+i]=1;
		For(i,1,top) {
			int u=a[i].u,v=a[i].v,d=a[i].d;
			if(!vis[u]&&!vis[v]&&fnd(u)!=fnd(v)) fa[fnd(u)]=v,res+=d;
		}
		
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}

