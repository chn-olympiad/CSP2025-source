#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int mod=998244353;
int num[5005]={},n;
int dfs(int maxx,int he,int now,int xuanze){
	if(now>=n+1){
		if(xuanze>=3&&he>maxx*2)
		  return 1;
		return 0;
	}
	return (dfs(max(maxx,num[now]),he+num[now],now+1,xuanze+1)+dfs(maxx,he,now+1,xuanze))%mod;
}
signed main(){
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	int maxxnum=-1;
	for(int i=1;i<=n;i++)
	  cin>>num[i],maxxnum=max(maxxnum,num[i]);
	if(maxxnum==1){
		long long ans=0,shang=n*(n-1)*(n-2)/6%mod;
		ans+=shang;
		for(int i=4;i<=n;i++){
			shang=shang*(n-i+1)/i%mod;
			ans=(ans+shang)%mod;
		}
		cout<<ans%mod;
	}
	else
	  cout<<dfs(0,0,1,0);
	return 0;
}
