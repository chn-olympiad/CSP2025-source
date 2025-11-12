#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
char str[1000];
int c[1000];
bool pass[1000];
bool used[1000];
int order[1000]; 
int fail[1000];
ll jc[1000];
int m,n;
int num;
ll ans;
void init(){
	jc[1]=1;
	for (int i=2;i<=n;i++){
		jc[i]=(jc[i-1]*i)%mod;
	}
} 
void dfs(int dep,int num){
	if (dep==n+1){
		if (num>=m) ans=(ans+1)%mod;
		return;
	}
	if (num>=m){
		ans=(ans+jc[n-dep+1])%mod;
		return;
	}
	for (int i=1;i<=n;i++){
		if (used[i]) continue;
		used[i]=true;
		order[dep]=i;
		if (c[i]>fail[dep-1]&&pass[dep]){
			fail[dep]=fail[dep-1];
			dfs(dep+1,num+1);
		} 
		else{
			fail[dep]=fail[dep-1]+1; 
			dfs(dep+1,num); 
		} 
		used[i]=false;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",str);
	bool flag=1;
	int cntz=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if (c[i]==0) cntz++;
	} 
	for (int i=0;i<n;i++){
		pass[i+1]=str[i]-'0';
		if (pass[i+1]==1) flag=flag&&1;
		else flag=0;
	} 
	int cnt=0;
	init();
	for (int i=1;i<=n;i++){
		if (pass[i]) cnt++;
	} 
	if(cnt<m){
		printf("0");
		return 0;
	}
	if (n==m){
		if (flag&&cntz==0) printf("%lld",jc[n]);
		else printf("0");
		return 0;
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
