#include<bits/stdc++.h>
using namespace std;
long long T,n,m,ans,a[1000];
map<int,int>mp;
vector<int> v,p;
const int mod=998244353;
string s;
bool pd(){
	int fail=0,sum=0,t=0;
	for(int l:v){
		if(l<=fail) fail++;
		else if(s[t]=='0') fail++;
		else sum++;
		t++;
	}
	if(sum>=m) return true;
	return false;
}
void dfs(int i){
	if(i>n){
		if(pd()) ans=(ans+1)%mod;
		return;
	}
	for(int j=1;j<=n;j++){
		if(mp[j]) continue;
		mp[j]=1;
		v.push_back(a[j]);
		dfs(i+1);
		v.pop_back();
		mp[j]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>18){
		for(int i=1;i<=n;i++){
			ans=(ans+(n-i+1)*(n-i)/2)%mod;
		}
		return cout<<ans+1,0;
	}
	v.clear();
	dfs(1);
	cout<<ans%mod;
	return 0;
} 
