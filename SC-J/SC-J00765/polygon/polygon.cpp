#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)cout<<a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			long long x=0;
			for(int k=j;k<=j+i-1;k++)x+=a[k];
			if(x>(a[j+i-1]*2))ans++;
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
