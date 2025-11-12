#include<bits/stdc++.h>
using namespace std;



int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	if(a[1]+a[2]+a[3]>2*a[3])
		cout<<1;
	else
		cout<<0;
	return 0;
}
