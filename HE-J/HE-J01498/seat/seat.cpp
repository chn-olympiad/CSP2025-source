#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin >>n >>m;
	long long a[n*m+1];
	long long tar=0;
	for (long long i=1;i<=n*m;i++)
	{
		cin >>a[i];
		if (i==1)
		{
			tar=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for (long long i=1;i<=n*m;i++)
	{
		if(a[i]==tar)
		{
			tar=i;
			break;
		}
	}
	if (tar%n!=0)
	{
		cout <<tar/n+1 <<' ';
		if ((tar/n+1)%2==0)
		{
			cout <<n-tar%n+1;
		}
		else
		{
			cout <<tar%n;
		}
	}
	else 
	{
		cout <<tar/n <<' ';
		if ((tar/n)%4==1||(tar/n)%4==0)
		{
			cout <<n;
		}
		else
		{
			cout <<1;
		}
	}
	return 0;
}
