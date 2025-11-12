#include <bits/stdc++.h>
using namespace std;
int n,a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	 
	char c;
	while(cin>>c && c!=EOF)
	{
		if('0'<=c && c<='9')
		{
			a[++n]=c-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n; i>=1; i--)
	{
		cout<<a[i];
	}
	return 0;
 } 
