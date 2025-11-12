#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int n,m,k,u,v,w,ans,cnt;
int a[10011][10011],b[10011][10011];
bool f[10011];
void dfs(int x){
	bool s=0;
	for(int i=1;i<=n;i++) if(!f[i]) s=1;
	if(!s){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(x==i || f[i]) continue;
		f[i]=1;
		cnt+=b[i][x];
		dfs(i);
		f[i]=0;
		cnt-=b[i][x];
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=-1;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int x,q;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>q;
			a[x+n][j]=q+x;
			a[j][x+n]=q+x;
		}
	}
	
	for(int q=1;q<=n+k;q++){
		for(int i=1;i<=n+k;i++){
			for(int j=1;j<=n+k;j++){
				b[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	int min1=1000,h=1;
	for(int i=1;i<=n+k;i++){
		int sum=0;
		for(int j=1;j<=n+k;j++){
			if(i==j) continue;
			if(a[i][j]>=0) sum++;
		}
		if(sum<=min1) min1=sum,h=i;
	}
	f[h]=1;
	cnt=0;
	dfs(h);
	cout<<ans;
	return 0;
}
