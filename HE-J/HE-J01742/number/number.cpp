#include<bits/stdc++.h>
using namespace std;
int z[15];
int main()
{
	preopen("number.in","r",stdin);
	preopen("number.out","w",stdout);
	string a;
	cin >>a;
	int n=a.size();
	for (int i=0;i<n;i++)
	{
		if (a[i]>='0' && a[i]<='9')
		{
			z[a[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=z[i];j++)
		{
			cout <<i;
		}
	}
	return 0;
}
