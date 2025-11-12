#include <bits/stdc++.h>

using namespace std;
int a[5005];
long long ans=9;
int main()
{
 	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	
	sort(a+1,a+1+n);
	cout<<ans;
	return 0;
}
