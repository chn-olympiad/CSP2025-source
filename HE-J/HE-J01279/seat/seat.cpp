#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[1000],n,m,d=1,d1=1,s=0,s2=10000;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
	{
		cin>>a[i];
		if(s<a[i])
		{
			s=a[i];
		}
		if(a[i]<s2)
		{
			s2=a[i];
		}
	}
    if(s==a[1])
    {
    	cout<<n<<" "<<m;
	}
	if(s2==a[1])
	{
		cout<<d<<" "<<d1;
	}
	return 0;
}
