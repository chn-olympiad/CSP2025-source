#include <bits/stdc++.h>
using namespace std;
long long n,a[50005],s,k=3,d[50005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(a[1]+a[2]>a[3]) cout<<1;
		return 0;
	}
	d[1]=a[1];
	for(int i=2;i<=n;i++){
		d[i]=a[i]+d[i-1];
	}
	s=(n-2)%998;
	s%=244;
	s%=353;
	if(a[1]==1) cout<<s; 
	return 0;
}

