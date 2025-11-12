#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e6,M=998244353;
ll a[N],n;
ll dfs(int last,ll num,ll man,int lon){
	ll ans=0;
	for(int i=last+1;i<=n;i++){
		ans=(ans+dfs(i,num+a[i],max(man,a[i]),lon+1))%M;
	}
	if(lon>=3&&num>man*2){
		return (ans+1)%M;
	}else{
		return ans%M;
	}
	return ans%M;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool boo=false; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			boo=true;
		}
	}
	ll ans;
	if(boo=true){
		ans=dfs(0,0,0,0);
	}else{
		ll awa=0;
		ans=1;
		for(int i=3;i<=n;i++){
			ans=ans*2+awa;
			awa+=i;
		}
		if(n==3){
			ans=1;
		}
	}
	cout<<ans%M;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
