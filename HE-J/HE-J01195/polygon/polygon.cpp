#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long sum=0,ma=-1,ans=0;
	cin>>n;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(ma<a[i])ma=a[i];
	}
	for(int i=1;i<=2*n;i++){
		if(i>=3&&sum>ma*2){
			ans++;
		}
	}
	cout<<ans%mod;
	return 0;
}

