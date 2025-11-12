#include <bits/stdc++.h>
using namespace std;
int a[111111];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i]>>a[0]>>a[0];
		sort(a+1,a+n+1,greater<int>());
		int m=0;
		for (int i=1;i<=n/2;i++) m+=a[i];
		cout<<m<<endl;
	}
	return 0;
}
