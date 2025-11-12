#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1001011],ans,mod=998244353,b[1001011],f;
ll ts[10011101],ts1[10011101],ts2[10011101];
void dfs(ll j,ll sum,ll k,ll l){
	if(j==n+1){
		if(sum>a[k]*2&&l>=3) ans++;
		ans%=mod;
	}else{
		dfs(j+1,sum+a[j],j,l+1);
		dfs(j+1,sum,k,l);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(f==0){
		ts[1]=8;
		ts1[1]=4;
		ts2[1]=1;
		if(n==3) cout<<"1";
		else if(n==4) cout<<"5";
		else if(n==5) cout<<"16";
		else{
			for(ll i=2;i<=n;i++) ts[i]=ts[i-1]*2,ts[i]%=mod;
			for(ll i=2;i<=n;i++) ts1[i]=ts1[i-1]+ts[i-1]-1,ts1[i]%=mod;
			for(ll i=2;i<=n;i++) ts2[i]=ts2[i-1]+ts1[i-1],ts2[i]%=mod;
			cout<<ts2[n-2];
		}
		exit(0);
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
//1 5 16 42 99 219 466
//4 11 26 57 120 247
//7 15 31 63 127

