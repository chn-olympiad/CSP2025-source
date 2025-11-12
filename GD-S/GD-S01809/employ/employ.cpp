#include<bits/stdc++.h>
using namespace std;
string s;
long long a[505],n,vis[505],m,ans1;
void dfs(long long k,long long ans,long long fq){
	if(k<=n){
		for(long long i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[k-1]=='1'&&a[i]>fq){
				dfs(k+1,ans+1,fq);
			}
			else{
				dfs(k+1,ans,fq+1);
			}
			vis[i]=0;
		}	
        }
	}
	else{
		if(ans>=m){
    	ans1++;
    	ans1%=998244353;
	}
	}
    
}
int main(){	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1,0,0);
	cout<<ans1;
	return 0;
}
