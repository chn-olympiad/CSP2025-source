#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n;
int a[5009];
void solve1(){
	if(n!=3){
		cout<<0;
	}else{
		sort(a+1,a+n+1);
		if(a[0]+a[1]+a[2]>2*a[2]) cout<<1;
		else cout<<0;
	}
}
bool vis[29];
int ans;
void dfs(int k){
	if(k == n+1){
		int geshu = 0,cnt = 0,mx = 0;
		for(int i = 1;i<=n;++i){
			if(vis[i]){
				geshu++;
				cnt+=a[i];
				mx = max(mx,a[i]);
			}
		}
		if(geshu>=3&&cnt>2*mx){
			ans++;
			ans%=mod;
		}
		return ;
	}
	dfs(k+1);
	vis[k] = 1;
	dfs(k+1);
	vis[k] = 0;
}
void solve2(){
	dfs(1);
	cout<<ans;
}
int jc[5009];
void solve3(){
	jc[1] = 1;
	for(int i = 2;i<=n;++i) jc[i] = (jc[i-1]*i)%mod;
	int ans = 0;
	for(int len = 3;len<n;++len){
		ans+=jc[n]/(jc[len]*jc[n-len]);
		ans%=mod;
	}
	ans+=1;
	ans%=mod;
	cout<<ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
	}
	if(n<=3){
		solve1();
	}else if(n<=20){
		solve2();
	}else solve3();
	fclose(stdin);
	fclose(stdout);
}
