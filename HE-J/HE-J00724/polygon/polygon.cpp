#include<bits/stdc++.h>
using namespace std;
int a[1000086];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0;
	if(n==3)
	{
		if(a[0]+a[1]+a[2]>2*(max(a[0],max(a[1],a[2]))))
		ans++;
	}
	cout<<ans;
	return 0;
}
