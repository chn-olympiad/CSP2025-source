#include <bits/stdc++.h>
using namespace std;
string s;
int m,n,k,a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s; 
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[++k]=int(s[i]);
		}
	}
	for(int i=1;i<=k;i++)
	{
		m=0;
		n=0;
		for(int j=1;j<=k;j++)
		{
			if(a[j]>=0)
			{
				if(a[j]>m)
				{
					m=a[j];
					n=j;
				}
			}
		}
		cout<<char(m);
		a[n]=0;
	}
	return 0; 
}
