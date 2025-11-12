#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int f[10];
int linshi;
int shu;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	shu=sizeof(a);
	for (int i=0;i<shu;i++)
	{
		if (a[i]<='9' and a[i]>='0')
		{
			linshi=a[i]-'0';
			f[linshi]++;
		}
	}
	cout<<endl;
	for (int i=9;i>=0;i--)
	{
		for (int j=f[i];j>0;j--)
		{
			cout<<i;
		}
	}
	return 0;
 } 
