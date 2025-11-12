#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m;
int a[100005];
string s;
int c[100005];
bool v[25];
long long ans=0;
inline void dfs(int p,int sum){
	if(p>n){
		if(sum>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=1;
		int val=0;
		if(a[p]==1 && p-sum-1<c[i]){
			val=1;
		}
		dfs(p+1,sum+val);
		v[i]=0;
	}
	return ;
}
bool flag=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0';
		if(s[i]=='0'){
			flag=0;
		}
	}	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(flag){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans<<'\n';
		return 0;
	}
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}
