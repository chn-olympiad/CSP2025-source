#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long d;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m;
	long long l;
	cin>>m>>l;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	d=0;
	int cnt=0,g=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=g;j<=i;j++)
		{
			d=0;
			for(int k=j;k<=i;k++)
			{
				d=d^a[k];
			}
			if(d==l)
			{
				cnt++;
				d=0;
				g=i;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
