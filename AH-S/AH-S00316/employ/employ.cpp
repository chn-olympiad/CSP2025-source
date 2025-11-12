#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[503];
int a[503];
void init(){
	scanf("%d%d",&n,&m);
	cin>>c+1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	return;
}
long long ans;
bool vis[503];
void dfs(int nw,int ok){
	if(nw==n+1){
		if(ok>=m)ans++;
		return;
	}
	if(n-nw+1+ok<m)return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(nw+1,ok+(c[nw]=='1'&&(nw-ok-1)<a[i]));
			vis[i]=false;
		}
	}
	return;
}
void work(){
	dfs(1,0);
	printf("%lld",ans);
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t;
	//~ scanf("%d",&t);
	t=1;
	while(t--){
		init();
		work();
	}
	return 0;
}
