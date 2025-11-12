#include<bits/stdc++.h>
using namespace std;
long long f[10],z,n=1,m,i,j;
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	z=a.length();
	for(i=0;i<z;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			f[a[i]-'0']++;
			m++;
		}
	}
	for(i=9;i>=0;i--)
	{
		for(;f[i];)
		{
			printf("%lld",i);
			f[i]--;
		}
	}
	return 0;
}
