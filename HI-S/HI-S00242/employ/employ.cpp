#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505];
string s;
bool pd1=0;
long long ans;
int a[15];
bool use[15];
void dfs(int now){
	if(now==n+1){
		int fail=0,pass=0;
		for(int i=1;i<=n;++i){
			if(s[i-1]=='0'||fail>=c[a[i]]){
				fail++;
			}
			else{
				pass++;
			}
//			cout<<a[i]<<" ";
		}
//		cout<<":"<<pass<<" "<<fail<<"\n";
		if(pass>=m){
			ans++;
			ans%=mod;
		}
	}
	for(int i=1;i<=n;++i){
		if(use[i]==0){
			use[i]=1;
			a[now]=i;
			dfs(now+1);
			use[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	for(int i=0;i<n;++i){
		if(s[i]!='0'){
			pd1=1;
		}
	}
	if(pd1==0){
		ans=1;
		for(int i=1;i<=n;++i){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	else{
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
}
