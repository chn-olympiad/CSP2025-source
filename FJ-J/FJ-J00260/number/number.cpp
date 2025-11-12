#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[100005];
	int n=0,b[11];
	while(cin>>a[n])
	{
		n++;
	}
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			c=a[i]-'0';
			b[c]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(b[i])
		{
			cout<<i;
			b[i]--;
		}
	}
	return 0;
} 
