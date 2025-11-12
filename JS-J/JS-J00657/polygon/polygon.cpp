#include<bits/stdc++.h>
using namespace std;
long long sum[5005],a[5005];
long long ans;
int mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	sum[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=a[i]+1;j<=5001;j++)
			(ans+=sum[j])%=mod;
		for (int j=5001;j>=0;j--){
			(sum[min(5001ll,j+a[i])]+=sum[j])%=mod;
		}
	}
	cout<<ans;
	return 0;
}
