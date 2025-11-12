#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N];
long long c[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	if(n==3){
		if(a[1]+a[2]<=a[3]){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	long long ans=0;
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			long long t=a[i]-a[j];
			for(int k=1;k<j;k++){
				if(c[k]>t){
					ans+=(j-k+1);
					ans%=998344353;
				}
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}	
