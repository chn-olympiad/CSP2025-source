#include<bits/stdc++.h>
using namespace std;
int n,a[4];
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
	if(a[0]+a[1]<=a[2])
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
