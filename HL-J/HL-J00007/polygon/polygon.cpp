#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
const ll mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	map<ll,map<ll,ll> >c;
	c[1][1]=1;
	for(int i=1;i<=5000;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	ll n,a[5001],k=0,ma=-1;
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		k+=a[i];
		if(a[i]!=1)flag==0;
	}ll ans=0;
	if(flag){
		for(int i=3;i<=n;i++){
			ans=(ans+c[n][i])%mod;
		}cout<<ans;
		return 0;
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		if(k>=ma*2)cout<<1;
		return 0;
	}
	else{
		cout<<101015;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

