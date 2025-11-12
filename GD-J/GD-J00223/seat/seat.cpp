#include<bits/stdc++.h>
using namespace std;
int n,m,a[113];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int man=a[1];
	for(int i=1;i<n*m;i++)
	{
		for(int j=1;j<=n*m-i;j++)
		{
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
		}
	}
	int i = 1, j = 1, cnt = 1, fang = 0;
	while(1)
	{
		if(a[cnt]==man)
		{
			cout<<j<<' '<<i;
			break;	
		}	
		cnt++;
		if(fang==0)
		{
			if(i==n)
			{
				fang=1;
				j++;
			}
			else i++;
		}
		else
		{
			if(i==1)
			{
				j++;
				fang=0;
			}
			else i--;
		}
	}
	return 0;
}

