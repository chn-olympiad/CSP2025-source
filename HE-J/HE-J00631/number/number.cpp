#include <bits/stdc++.h>
using namespace std;
string s;
long long ans,a[10];
int main()
{
//	/*
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	 */
	cin>>s;
	int n=s.size();
	for(long long i=0;i<=n;i++)
	{
		char c=s[i];
		if(c>='0'&&c<='9')
		{
			int b=c-'0';
			a[b]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			printf("%d",i);
			a[i]--;
		}
	}
	return 0;
} 
