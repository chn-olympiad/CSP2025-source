#include <bits/stdc++.h> 
using namespace std;
const long long MOD=998244353;
int s[505],n,m,c[505],num[505] ,anss,vis[505];
void dfs(int now){
	if(now==n+1){
		int cnt=0,ok=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[num[i]]||s[i]==0){
				cnt++;
			} 
			else {
				ok++;
			}
		} 
		if(ok>=m){
			anss++;
//			for(int i=1;i<=n;i++) cout<<c[num[i]]<<" ";
//			cout<<cnt<<" dfff\n";
		} 
		anss%=MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			num[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
} 
int main(){
	freopen("employ.in","r",stdin) ;
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int flag=1,ho=0,hoc=0,chz=0;
	for(int i=1;i<=n;i++) {
		char cc;
		cin>>cc;
		if(cc=='1') s[i]=1;
		else s[i]=0;
		if(s[i]==0)  flag=0;
		ho|=s[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		hoc|=c[i];
		if(c[i]==0) chz=1;
	}
	if(ho==0||hoc==0||(chz==1&&n==m)||(flag==0&&n==m)){
		//没有s[i]==1; 
		cout<<0;
		return 0;
	}
	if(n<=10){//暴力 
		dfs(1);
		cout<<anss;
		return 0;
	}

	if(flag){
		//A性质
		long long ans=1; 
		for(long long  i=2;i<=n;i++) {
			ans*=1ll*i;
			if(ans>MOD) ans%=MOD;
		}
		cout<<ans;
		return 0;
	}if(!flag&&m==n){
		cout<<0;
		return 0;
	}
	if(m==1){
		
		long long ans=1,pl=0; 
		for(int i=2;i<=n-1;i++) {
			ans*=1ll*i;
			if(ans>=MOD) ans%=MOD;
		}//算出（n-1)!
		int fo=0;
		for(int i=1;i<=n;i++){
			if(s[i]) {
				fo=i;
				break;
			}
		}
		for(int i=1;i<=n;i++) {
			if(fo-1<c[i]) pl++;
		}
		ans*=pl;
		if(ans>=MOD) ans%=MOD;
		cout<<ans;
		return 0;
	}
	return 0;
}
