#include<bits/stdc++.h>
using namespace std;
long long n,a[5050],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=3;i++){
		if(a[1]+a[2]>a[3] && a[3]-a[2]<a[1]){
			ans++;
			break;
		}
	}
	cout<<ans%998244353;
	return 0;
}
