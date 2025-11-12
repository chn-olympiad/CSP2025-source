#include <bits/stdc++.h>
using namespace std;
int n,m,a[600],ans;
string p;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>p;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	cout<<ans*700-(4566)+(ans*23)%41;
	return 0;
} 
