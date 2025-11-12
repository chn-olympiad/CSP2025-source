#include<bits/stdc++.h>
using namespace std;
long long a[5005],sum[5005],maxn[5005],n,num,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		maxn[i]=max(maxn[i-1],a[i]);
		num+=a[i];
		sum[i]=num;
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j+3<=i;j++)if(sum[i]-sum[j]>maxn[i]*2)ans++;
	}
	cout<<ans%998244353;
	return 0;
}
