#include<iostream>
#include<algorithm>
using namespace std;
#define N 998244353
int ans,x,n,m,p[501],cnt,f[501];
string s;
void dfs(int k,int sum){
	if(k==n+1){
		if(sum>=m) ans=(ans+1)%N;
		return ;
	}
	for(int i=1;i<=n;++i){
		if(!f[i]){
			f[i]=1;
			if(s[i-1]=='1'&&k-sum-1<=p[i]) dfs(k+1,sum+1);
			else dfs(k+1,sum);
			f[i]=0;
		}
	}
}
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();++i){
		cnt+=(s[i]=='0');
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	if(m==n){
		if(cnt>0) {
			cout<<0;
			return 0;
		}
	}
	else if(cnt==0){
	  	long long ans=1;
	  	for(int i=1;i<=n;i++){
	  		ans=(ans*i)%N;
	  	}
	  	cout<<ans%N;
	  	return 0;
	}
	else if(n-cnt<m){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}