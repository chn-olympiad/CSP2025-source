#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long sum;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		if(a[1] + a[2] + a[3] >2 * a[1] && a[1] + a[2] + a[3] > 2 * a[2] && a[1] + a[2] + a[3] > a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	else{
		sort(a+1,a+n+1);
		for(int i=3;i<=n;i++){
			for(int j=i;j<=n;j++){
				sum=0;
				for(int k=j;k>j-i;k--){
					sum+=a[k];
				}
				if(sum>2*a[j]){ans++;
					cout<<sum<<endl;
				}
			}
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
