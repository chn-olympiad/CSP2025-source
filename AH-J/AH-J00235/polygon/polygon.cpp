#include<bits/stdc++.h>
using namespace std;
long long a[110];
long long n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3)
		if(max(max(a[1],a[2]),a[3])*2<a[1]+a[2]+a[3])
			cout<<1;
	cout<<n;
	return 0;
}
