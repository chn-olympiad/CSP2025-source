#include<bits/stdc++.h>
using namespace std;
string a;
int n,b[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>-1;i--)
	{
		for(int j=1;j<=b[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
