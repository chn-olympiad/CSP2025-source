#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int a[505];
bool vis[505];
string s;
int n, m;
ll ans=0;
void dfs(int x, int now, int ref, int sum){
	//cout<<x<<" "<<now<<" "<<ref<<" "<<sum<<endl;
	if(now>=n){
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		if(s[now]=='1' && a[i]>ref) dfs(x+1, now+1,  ref, sum+1);
		else dfs(x+1, now+1, ref+1, sum);
		vis[i]=false;
	}
}
		
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		cnt+=(a[i]==0);
	}
	if(n<=10){
		dfs(1, 0, 0, 0);
		printf("%lld", ans);
		return 0;
	}
	bool flag=true;
	ans=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0') flag=false;
		ans=ans*(i+1)%mod;
	}
	if(flag){
		if(n-cnt>=m) printf("%lld", ans%mod);
		else printf("0");
	}
	return 0;
}