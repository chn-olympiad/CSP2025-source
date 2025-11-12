#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[10005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<=2){cout<<0;}
	else
	{
		if(a[0]+a[1]>a[2]){cout<<1;}
		else{cout<<0;}
	}
	return 0;
}