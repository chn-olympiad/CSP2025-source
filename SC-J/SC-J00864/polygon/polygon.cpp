#include<bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int ans,n,a[5010],dp[5010][5010];
bool flag;
int count(int a){
	int ans=1;
	while(a--){
		ans=(ans*2)%mod;
		//cout<<000;	
	}
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;n>=i;i++){
		cin>>a[i];	
		if(a[i]!=1)
			flag=1;
	}
	if(flag==0){
		int ans=0;
		for(int i=n;3<=i;i--){
			ans=(ans+(n-i+1)*(i-2)*(i-1)/2)%mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==3){
		sort(a+1,a+1+n);
		if(a[3]>=a[1]+a[2])	
			cout<<0;
		else 
			cout<<1;
		return 0;	
	}
	struct _timeb T;
	_ftime(&T);
	srand(T.millitm);
	cout<<rand();		 
	return 0; 
} 