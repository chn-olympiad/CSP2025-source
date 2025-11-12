#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int read();
int n,m,k,c[20],a1[20][10010],fa[10010],ans,cnt,minn1[20][10010];
bool f[20];
struct node{
	int u,v,w;
}a[1000010];
bool cmp(node x,node y) {
	return x.w<y.w;
}
int find(int x) {
	if(x==fa[x]) return fa[x];
	return fa[x]=find(fa[x]);
}
void solve(int sum) {
	cnt=0;
	for(int i=1;i<=n;i++) {
		fa[i]=i;
	}
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=n;j++) {
			if(f[i]) {
				minn1[i][j]=a1[i][j];
			}
		}
	}
	for(int i=1;i<=m;i++) {
		int u=find(a[i].u),v=find(a[i].v);
		if(u!=v) {
			fa[u]=v;
			int minn=a[i].w;
			for(int j=1;j<=k;j++) {
				if(f[j]) {
					minn=min(minn,minn1[j][u]+minn1[j][v]);
				}
			}
			sum+=minn;
			cnt++;
			if(cnt==n-1) {
				break;
			}
			for(int j=1;j<=k;j++) {
				if(f[j]) {
					minn1[j][v]=minn1[j][u]=min(minn1[j][v],minn1[j][u]);
				}
			}
		}
	}
	ans=min(ans,sum);
}
void dfs(int k1,int sum) {
	if(k1>k) {
		solve(sum);
		return;
	}
	if(c[k1]==0) {
		f[k1]=true;
		dfs(k1+1,sum);
		f[k1]=false;
		return;
	}
	dfs(k1+1,sum);
	f[k1]=true;
	dfs(k1+1,sum+c[k1]);
	f[k1]=false;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) {
		fa[i]=i;
	}
	for(int i=1;i<=m;i++) {
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	for(int i=1;i<=k;i++) {
		c[i]=read();
		for(int j=1;j<=n;j++) {
			a1[i][j]=read();
		}
	}
	sort(a+1,a+m+1,cmp);
	if(k==0) {
		for(int i=1;i<=m;i++) {
			int u=find(a[i].u),v=find(a[i].v);
			if(u!=v) {
				fa[u]=v;
				ans+=a[i].w;
				cnt++;
				if(cnt==n-1) {
					cout<<ans;
					return 0;
				}
			}
		}
	}
	ans=1000000000000000;
	dfs(1,0);
	cout<<ans;
	return 0;
}
int read(){
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-1;}}
	while(Cr>='0' && Cr<='9') {Ca=Ca*10+Cr-48;Cr=getchar();}
	return Ca*Cf;
}