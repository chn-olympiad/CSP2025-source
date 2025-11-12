#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[510];
int b[510];
int c[510];
bool vis[510];
int mod=998244353;
long long ans=0;
void dfs(int k){
	if(k==n){
		return ;
	}
	if(c[k]==m){
		ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i] && a[i]>b[k]){
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n>>m;
cin>>s;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=0;i<s.size();i++){
	if(s[i]=='0'){
	b[i]++;
}else{
	c[i]++;
}
c[i]=c[i-1]+c[i];
b[i]=b[i-1]+b[i];
}
if(c[n]==s.size()){
for(int i=1;i<=n;i++){
	ans*=i%mod;
}
}
else	
dfs(0);
cout<<ans;
return 0;
}
