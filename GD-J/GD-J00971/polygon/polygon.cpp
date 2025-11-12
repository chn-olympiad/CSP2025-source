#include<bits/stdc++.h>
using namespace std;
long long a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n,m=0,b=0,c=0,d=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			d++;
			if(a[j]>b) b=a[j];
			c+=a[j];
			if(c>b*2&&d>=3)
			{
				m++;
				b=0;
			}
		}
		d=0;
	}
	cout<<m;
	return 0;
}
