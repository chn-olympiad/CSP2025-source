#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
const int N=2e6+7;
struct edge {
	int u,v,w;
	bool operator <(const edge &h)const {
		return w<h.w;
	}
};
vector<edge>e;
int n,m,k,fa[N],c[20],ans=1e14;
int find(int x) {
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
int solve(int p) {
	int sum=n,res=0;
	for(int i=1;i<=k;i++) {
		if((p>>(i-1))&1) {
			sum++;
			res+=c[i];
		}
	}
	
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int s=0;
	for(auto t:e) {
		int u=t.u,v=t.v,w=t.w;
		if(u>n&&!((p>>(u-n-1))&1))continue;
		if(v>n&&!((p>>(v-n-1))&1))continue;
		int x=find(u),y=find(v);
		if(x==y)continue;
		fa[x]=y;
		res+=w;
		if(res>=ans)return res;
		s++;
		if(s==sum-1)break;
	}
	return res;
}
int read() {
	int f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9') {
		f=f*10+ch-'0';
		ch=getchar();
	}
	return f;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++) {
		int u,v,w;u=read();v=read();w=read();
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++) {
		c[i]=read();
		for(int j=1;j<=n;j++) {
			int w;
			w=read();
			e.push_back({i+n,j,w});
		}
	}
	sort(e.begin(),e.end());
	for(int p=0;p<(1<<k);p++)ans=min(ans,solve(p));
	printf("%lld",ans);
	return 0;
}
