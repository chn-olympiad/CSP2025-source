#include<bits/stdc++.h>
using namespace std;
string a;
long long g[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			g[a[i]-'0']++;
			
		}
	}
	for(long long i=9;i>=0;i--)
	{
		
		while(g[i])
		{
			cout<<i;
			g[i]--;
		}
	}
	return 0;
}
