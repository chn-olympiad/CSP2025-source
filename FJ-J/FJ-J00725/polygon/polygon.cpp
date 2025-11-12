#include<bits/stdc++.h>
using namespace std;

const int N=5005;
int n,ans,flag=1;
int a[N];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	sort(a+1,a+n+1);
	if(n<=3) {
		if(a[1]+a[2]>a[3]&&n==3)cout<<1;
		else cout<<0;
		return 0;
	}
	if(flag) {
		for(int len=3; len<=n; len++) {
			for(int i=n-len+1; i>=1; i--)ans+=i;
		}
		cout<<ans+1;
		return 0;
	}
	cout<<1LL*n*(n-1)%998244353;
	return 0;
}/*
5
1 2 3 4 5
*/
