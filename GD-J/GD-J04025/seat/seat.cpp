#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100],num=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++)
	{
		if(a[i]>a[0])
		{
			num++;
		}
	}
	int nn,nnn=n;
	if(num%n!=0)
	{	
		nn=1;
		nnn=num%n;
	}
	else
	cout<<num/n+nn<<' ';
	if((num%n+nn)%2==0)
	{
		cout<<nnn;
	}
	else
	{
		cout<<n-nnn+1;
	}
	return 0;
}
