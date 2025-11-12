#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],cnt;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	long long m=3;
	sort(a+1,a+1+n);
	if(a[1]+a[2]>a[3])cnt++;
	cout<<cnt;
	return 0;
}
