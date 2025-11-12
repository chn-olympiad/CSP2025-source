#include <bits/stdc++.h>
using namespace std;
int a[500005],o[500005],n,m,s,l;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=m)
		{
			o[i]=o[i-1]^a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==m)
		{
			s++;
			l=i;
		}
		else
		{
			for(int j=l+1;j<i;j++)
			{
				if((o[j-1]^o[i])==m)
				{
					s++;
					l=j;
					break;
				}
			}
		}
	}
	cout<<s;
}
