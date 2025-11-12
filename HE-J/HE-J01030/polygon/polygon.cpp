#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5050];
int sum[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--){
		if(sum[i]>2*a[i]){
			ans+=i;
		}
	}
	cout<<ans;
	return 0;
}
