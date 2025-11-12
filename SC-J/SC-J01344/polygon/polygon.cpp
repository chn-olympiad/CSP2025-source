#include<bits/stdc++.h>
#define mod 998244353 
#define N (int)5e3+5
using namespace std;
int n,a[N];
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<(1<<n);i++){
		int sum=0,mx=-1,cnt=0;
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			sum+=a[j+1];
			mx=max(mx,a[j+1]); 
			cnt++;
		}
		if(cnt>=3&&sum>mx*2)ans=(ans+1)%mod;
	}
	cout<<ans%mod;
	return 0;
	
} 