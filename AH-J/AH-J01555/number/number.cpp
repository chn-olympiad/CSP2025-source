#include<bits/stdc++.h>
using namespace std;
int s[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,n;
	string a;
	cin>>a;
	n=a.size();
	for(i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			s[a[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--)
	{
		for(j=1;j<=s[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
