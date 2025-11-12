#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int>a(n+5);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.begin()+n+1);
	if(a[n]>=a[1]+a[2]) cout<<0;
	else cout<<1;
	cout<<endl;
	return 0;
}
