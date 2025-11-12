#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	cin>>n;
	int a[n+5];
	int s=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]+a[2]+a[3]>a[n]*2)
		cout<<
	return 0;
}
