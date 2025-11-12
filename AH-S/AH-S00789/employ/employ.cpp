#include<bits/stdc++.h>
using namespace std;
int a[505],v[505],n,m;
long long ans;
string s;
void dfs(int nan,int sum,int k){
	if(k==n){
		if(sum>=m) ans++;
		return;
	}
	if(n-k<m-sum) return;
	if(s[k]=='0'){
		for(int i=1;i<=n;i++) if(!v[i]){
			v[i]=1;
			dfs(nan+1,sum,k+1);
			v[i]=0;
		}
	}
	else{
		for(int i=1;i<=n;i++) if(!v[i]){
			v[i]=1;
			if(a[i]>nan) dfs(nan,sum+1,k+1);
			else dfs(nan+1,sum,k+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=18){
		dfs(0,0,0);
		cout<<ans;
	}
	else if(n==m){
		for(int i=1;i<=n;i++) if(s[i-1]=='0'||!a[i]){
			cout<<0;
			return 0;
		}
		int ans=1;
		for(long long i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++) if(!a[i]) m++;
		if(m>n){
			cout<<0;
			return 0;
		}
		int ans=1;
		for(long long i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
