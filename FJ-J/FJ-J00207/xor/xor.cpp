#include<bits/stdc++.h>
using namespace std;
int n,k,s[500005],c;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n >>k;
	for (int i=1;i <= n; i++)
	cin >>s[i];
	int l=1;
	for (int i=1;i <= n;i++)
	{
		for (int j=l;j<=i;j++)
		{
			int d=0;
			for (int k=j;k<=i;k++)
			d^=s[k];
			if (d==k)
			{
				c++;
				l=i+1;
				break;
			}
		}
	}
	cout <<c;
	return 0;
}
