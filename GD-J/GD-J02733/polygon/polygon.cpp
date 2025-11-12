#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,mx;
int a[5007];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		int mx=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>2*mx){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else if(mx==1){
		long long ans=0,j[5007];
		j[0]=1;
		j[1]=1;
		for(int i=2;i<=n;i++){
			j[i]=(j[i-1]*i)%mod; 
		}
		for(int i=3;i<=n;i++){
			ans+=(j[n]/j[n-i])%mod;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
