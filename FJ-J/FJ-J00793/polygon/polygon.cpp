#include <bits/stdc++.h>
using namespace std;
long long c(int n,int m){
	long long s=1;
	for(int i=n;i>=n-m+1;i--){
		s*=i;
	}
	for(int i=1;i<=m;i++){
		s/=i;
	}
	return s;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin >> n;
	if(n<3){
		cout << 0;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag==1){
		long long ans=0;
		
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
			ans%=998244353;
		}
		cout << ans;
		return 0;
	}
	if(n==3){
		int maxn=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>maxn*2) cout << 1;
		else cout << 0;
	}
	return 0;
}

