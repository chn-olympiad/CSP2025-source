#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define debug(x) cerr<<"debug: "<<#x<<" = "<<x<<endl
using namespace std;
namespace code{
	inline int read(){
		int f=1;int x=0;char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=-f;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+(ch-'0');
			ch=getchar();
		}
		return f*x;
	}
	int n,m,k,sum;
	int cx[15][10005];
	struct node{
		int u,v,w;
	}p[1000005],q[10005];
	bool cmp(node x,node y){
		return x.w<y.w;
	}
	int f[10005];
	int find(int x){
		if(f[x]==x) return x;
		return f[x]=find(f[x]);
	}
	signed main(){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++) p[i]={read(),read(),read()};
		for(int i=0;i<=k;i++) for(int j=1;j<=n;j++) cin>>cx[i][j];
		sort(p+1,p+m+1,cmp);
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=m;i++){
			int u=p[i].u,v=p[i].v,w=p[i].w;
			if(find(u)==find(v)) continue;
			f[find(u)]=find(v);
			sum+=w;
		}
		cout<<sum;
		return 0;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	return code::main();
}
