#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f[105],an=0;
	cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
		cin>>f[i];
	}
	int sn=f[0];
	sort(f,f+n*m);
	for(int i=0;i<n*m;i++)
	{
		if(f[i]==sn)break;
		an++;
	}
	int su;
	su=n*m-an;
	if(su==1)
	{
		cout<<"1 1";
		return 0;
	}
	if(su%n==0&&su/n<=1)
	{
		cout<<"1"<<" "<<su;
		return 0;
	}
	cout<<ceil(su/2)<<" ";
	int hu=ceil(su/2);
	if(hu%2==0)
	{
		if(su%2==1)
		{
			cout<<n;
			return 0;
		}
		 if(su%2==2)
		{
			cout<<n-1;
			return 0;
		}
		if(su%2==3)
		{
			cout<<n-2;
			return 0;
		}
		if(su%2==4)
		{
			cout<<n-3;
			return 0;
		}
		if(su%2==5)
		{
			cout<<n-4;
			return 0;
		}
		if(su%2==6)
		{
			cout<<n-5;
			return 0;
		}
		if(su%2==7)
		{
			cout<<n-6;
			return 0;
		}
		if(su%2==8)
		{
			cout<<n-7;
			return 0;
		}
		if(su%2==9)
		{
			cout<<n-8;
			return 0;
		}
	}
	if(hu%2!=0)
	{
		cout<<su%n;
	}
    return 0;
}
