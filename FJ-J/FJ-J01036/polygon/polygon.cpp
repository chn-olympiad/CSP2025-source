#include <bits/stdc++.h>
using namespace std;
int n;
long long sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	int a[5];
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		if(a[i]>maxx)
		maxx=a[i];
	}
	if(sum>2*maxx)
	{
		cout<<n/3;
	}
	else{
		cout<<"0";
	}
	return 0;
}
