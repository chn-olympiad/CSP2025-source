#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010],ans=0;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	for(int j=2;i<=n;i++)
	for(int k=3;i<=n;i++)
	if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[k]+a[j]>a[i]&&i!=j&&i!=k&&j!=k)
	ans++;
	cout<<ans<<endl;
	return 0;	
} 
