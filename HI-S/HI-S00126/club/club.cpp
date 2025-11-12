#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int t;
int n;
int a[MAXN][4];
int c[MAXN],d[MAXN],e[MAXN];
int b[4];
int ans;
void dfs(const int& k,const int& sum){
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if((b[i]+1)*2<=n){
			b[i]++;
			dfs(k+1,sum+a[k][i]);
			b[i]--;
		}
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	ans=b[1]=b[2]=b[3]=0;
	if(n<=30) dfs(1,0);
	else{
		for(int i=1;i<=n;i++) c[i]=a[i][1],d[i]=a[i][2],e[i]=a[i][3];
		sort(c+1,c+n+1,greater<int>());
		sort(d+1,d+n+1,greater<int>());
		sort(e+1,e+n+1,greater<int>());
		for(int i=1;i<=n/2;i++) ans+=c[i]+d[i]+e[i];
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
