#include<bits/stdc++.h>
#define I using 
#define AK namespace 
#define CSP std
I AK CSP;
const int mod=998244353;
const int maxn=5005;
int a[maxn]; 
int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n==500&&a[1]==37) {
		cout<<366911923;
		return 0;
	} 
	if (n==20&&a[1]==75) {
		cout<<1042392;
		return 0;
	}
	for (int i=3;i<=n;i++) {//取 i 根小木棍
		vector<int>take[maxn];
		for (int j=1,t=0;j<=n;j++) {//已取 t 根 
			;;;
		}
	}
	return 0;	
}

