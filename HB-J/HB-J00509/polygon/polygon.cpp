#include<bits/stdc++.h>
using namespace std;
int n;
int a[5009];
long long h;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<((n+1)*n/4)%998244353;
	return 0;
}
