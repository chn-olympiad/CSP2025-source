#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		 maxx=max(maxx,a[i]);
	}
	if(a[1]+a[2]+a[3]>2*maxx)
	{
		cout<<1;
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
