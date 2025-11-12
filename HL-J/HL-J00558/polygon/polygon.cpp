#include<bits/stdc++.h>

using namespace std;
int n;
int a[5010];
const long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int maxx=-1;
		int sum=0;
		for(int i=1;i<=3;i++){
			maxx=max(maxx,a[i]);
			sum+=a[i];
		}
		maxx*=2;
		if(sum>maxx){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int maxx=-1;
			int sum=0;
			if((j-i+1)<3){
				continue;
			}
			for(int k=i;k<=j;k++){
				maxx=max(maxx,a[k]);
				sum+=a[k];
			}
			maxx*=2;
			if(sum>maxx){
				ans++;
			}
		}
	}
	cout<<ans%mod;
	return 0;
}

