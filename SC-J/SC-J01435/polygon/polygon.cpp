#include<bits/stdc++.h>
using namespace std;
const long long N= 998244353; 
long long cnt,n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else {
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		long long sum=0;
		for(int j=1;j<=i;j++){
			sum+=a[i];
		}
		for(int j=n;j>i;j--){
			if(sum>a[i])  cnt++;
		}
	}
	cout<<cnt;
	return 0;
}