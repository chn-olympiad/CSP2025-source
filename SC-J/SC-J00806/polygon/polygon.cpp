#include<bits/stdc++.h>
using namespace std;
int n,a[5050];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==3)
	{
		if(a[0]+a[1]+a[2]>2*max(max(a[0],a[1]),a[2]))
		cout<<1;
		else cout<<0;
	} 
	else if(n>3&&n<=20)
	{
		cout<<a[n-1]+a[n-2];
	}
	return 0;
}