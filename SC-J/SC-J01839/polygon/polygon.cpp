#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
int s[5005];
int c[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	c[1]=1;
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]*(c[i]+1)%998244353;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		int x=upper_bound(s+1,s+1+n,a[i])-s;
		for(int j=x;j<n;j++){
			int y=j-1;
			int bs=j-2;
			ans+=c[y]/(c[bs]*c[y-bs]);
		}
	}
	cout<<ans;
	return 0;
} 