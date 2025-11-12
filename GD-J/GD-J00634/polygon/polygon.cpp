#include<bits/stdc++.h>
using namespace std;
int a[5001],b[5001];
int ans;
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
	if(n<3) cout<<0<<endl;
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cout<<1<<endl;
	}
	if(n==4)
	{
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) ans++;
		if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2) ans++;
		if(a[3]+a[2]+a[4]>max(a[3],max(a[2],a[4]))*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]>max(a[1],max(a[2],max(a[3],a[4])))*2) ans++;
	}
	if(n>4)
	{
		cout<<1<<endl;
	}
	return 0;
}
