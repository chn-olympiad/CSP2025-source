#include<bits/stdc++.h>
#define int long long
using namespace std;
struct sbb {
	int a,b,qz;
} sb[2000005];
struct DL {
	int a,b,qz;
} dl[100005];
int n,m;
int fa[10104];
bool cmp(const sbb &t1,const sbb &t2) {
	return t1.qz<t2.qz;
}
bool ccmp(const DL &t1,const DL &t2) {
	return t1.qz<t2.qz;
}
int b[15][10005];
int xq[15];
int k;
int ans=1e17;
int cut;

int Find(int wz) {
	if(fa[wz]==wz)return wz;
	fa[wz]=Find(fa[wz]);
	return fa[wz];
}
void dfs(int wz,int nans) {
	if(nans>=ans)return ;
	if(wz<=k) {
		dfs(wz+1,nans);
		xq[wz]=1;
		nans+=b[wz][0];
		dfs(wz+1,nans);
		return ;
	}
	cut=0;
	for(int i=1; i<=n+k; i++)fa[i]=i;
	for(int i=1; i<=k; i++) {
		if(xq[i]==0)continue;
		for(int j=1; j<=n; j++)dl[++cut].a=n+i,dl[cut].b=j,dl[cut].qz=b[i][j];
	}
	sort(dl+1,dl+1+cut,ccmp);
	return ;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)fa[i]=i;
	for(int i=1; i<=m; i++)cin>>sb[i].a>>sb[i].b>>sb[i].qz;
	cut=m;
	for(int i=1; i<=k; i++) {
		int pd=0,wz;
		for(int j=0; j<=n; j++) {
			cin>>b[i][j];
			if(j!=0&&b[i][0]==0&&b[i][j]==0)pd=1,wz=j;
		}
		if(pd==1) {
			for(int nwz=1; nwz<=n; nwz++) {
				if(nwz==wz)continue;
				sb[++cut].a=wz,sb[cut].b=nwz,sb[cut].qz=b[i][nwz];
			}
		}
	}
	sort(sb+1,sb+1+cut,cmp);
	ans=0;
	int lt=1;
	for(int i=1; i<=cut; i++) {
		if(Find(sb[i].a)!=Find(sb[i].b)) {
			fa[Find(sb[i].a)]=Find(sb[i].b);
			ans+=sb[i].qz;
			if(++lt==n)break;
		}
	}
	cout<<ans;
	return 0;
}
