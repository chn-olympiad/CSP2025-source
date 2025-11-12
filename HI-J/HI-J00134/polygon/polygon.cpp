#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a[10005],sum;
int jiecheng(int m){
	int num=1;
	for(int i = 1; i <= m; i++)num*=i;
	return num;
}
int c(int q,int w){
	return jiecheng(w)/(jiecheng(q)*jiecheng(w-q));
}
signed main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n; i++)cin >> a[i];
	for(int i = 3; i<=n;i++){
		sum+=c(i,n);
	}
	cout << sum%998244353;
	return 0;
}

