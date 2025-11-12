#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main()
{
	freopen("munber.in","r",stdin);
	freopen("munber.out","w",stdout);
	char b;
	while(cin>>b)
	{
		if(b>='0'&&b<='9')
		a[b-'0']++;
	}
	for(long long i=9;i>=0;i--)
	{
		for(long long o=0;o<a[i];o++)
		{
			cout<<i;
		}
	}
	return 0;
 } 