#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50010],s[50010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1){
		int k=1;
		for(int i=1;i<=n;i++)
			k=(k*2)%998244353;
		cout<<(k+998244353-1-n*n)%998244353;
		return 0;
	}
	s[0]=0;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	long long ans=0ll;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i-2;j++){
			if(s[i]-s[j-1]>2*a[i]&&s[i]-s[j]<=2*a[i])
				ans=(ans+(1<<(j-1))%998244353)%998244353;
		}
		ans=ans%998244353;
	}
	cout<<ans;
	return 0;
}
