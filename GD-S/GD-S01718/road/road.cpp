#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=1000006;
typedef long long ll;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') x = x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,k,fa[N],a[15][N],c[15];
ll ans = 1e9,sum = 0;
struct edge{
	int x,y,v;
}e[2*M],e2[2*M];
vector<edge> G;
bool cmp(edge x,edge y){
	return x.v<y.v;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
ll cal(int S){
	ll exp = 0,an = sum;
	for(int i=0;i<k;i++){
		if(S&(1<<i)) {
			exp += c[i+1];
		}
	}
	for(int i=0;i<n-1;i++){
		int res = G[i].v;
		for(int j=0;j<k;j++){
			if(S&(1<<j)){
				res = min(res,a[j+1][G[i].x]+a[j+1][G[i].y]);
				cout<<"i="<<i<<" j="<<j<<" add="<<a[j+1][G[i].x]+a[j+1][G[i].y]<<" x="<<G[i].x<<" y="<<G[i].y<<endl;
			}
		}
		an = (an - G[i].v + res);
	}
	cout<<an+exp<<endl;
	return an+exp;
}

namespace test1{
void work(){
	int all = (1<<k)-1;
	for(int i=0;i<=all;i++){
		for(int i=1;i<=n+k;i++) fa[i]=i;
		ll res = 0;
		int tot = m,n1=n;
		for(int i=1;i<=m;i++) e2[i]=e[i];
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				for(int k=1;k<=n;k++){
					e2[++tot] = (edge){n+j+1,k,a[j+1][k]};
				}
				res += c[j+1]; n1++;
			}
		}
		sort(e2+1,e2+tot+1,cmp);
		int cnt = 0;
		for(int i=1;i<=tot;i++){
			int u = find(e2[i].x), v=find(e2[i].y);
			if(u==v) continue;
			res += e2[i].v;
			fa[u] = v;
			if(cnt == n1-1) break;
		}
//		cout<<res<<endl;
		ans = min(res,ans);
	}
	printf("%lld\n",ans);
}

} 
namespace test2{
void work(){
	sort(e+1,e+m+1,cmp);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		int u = find(e[i].x), v=find(e[i].y);
		if(u==v) continue;
		sum += e[i].v;
		fa[u] = v; cnt++;
		G.push_back((edge){e[i].x,e[i].y,e[i].v});
		if(cnt == n-1) break;
	}
	int all = (1<<k)-1;
	for(int i=1;i<=all;i++){
		ans = min(cal(i),ans);
	}
}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++) e[i].x=read(),e[i].y=read(),e[i].v=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	test1::work();
	return 0;
}
