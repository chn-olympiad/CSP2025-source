#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],num=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	num+=(n+n*(n-3))*(n-3)/2;
	cout<<num;
	return 0;
}
