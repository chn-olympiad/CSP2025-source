#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,b[505],a[505],m,qz[505],ans,dp[505][505];
string s; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) a[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==0) qz[i]=qz[i-1]+1;
		else qz[i]=qz[i-1];
	} 
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				int k=upper_bound(b+1,b+1+n,qz[i])-b;
				ans+=n-k+1,ans%=mod; 
			}
		} 
	} 
	cout<<ans;
	return 0;
} 
