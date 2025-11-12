#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005];
const int M=998244353;

int pw(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=(ans*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return ans;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	bool type1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) type1=0;
	}
	if(type1){
		int ans=pw(2,n)-n*(n-1)/2-n-1;
		while(ans<0){
			ans+=M;
		}
		ans%=M;
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++){
		int gs=0,sum=0,mx=0;
		for(int j=0;j<n;j++){
			if((1<<j)&i){
				gs++;
				sum+=a[j+1];
				mx=max(mx,a[j+1]);
			}
		}
		if(gs>=3&&sum>2*mx){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
