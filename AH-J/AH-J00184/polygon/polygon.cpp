#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int n,a[5005];
long long q=1,k;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=n;j>=n-i+1;j--){
			q*=j;
			q%=mod;
		}
		for(int j=1;j<=i;j++){
			q/=j;
		}
		k+=q;
		k%=mod;
		q=1;
	}
	cout<<k;
	return 0;
}
