#include<bits/stdc++.h>

using namespace std;
string a;
long long x[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.size();i++)
	{
		if(a[i]>='0' && a[i]<='9') x[a[i]-'0']++;
	}
	for(long long i=9;i>=0;i--)
	{
		for(long long j=1;j<=x[i];j++)
		{
			printf("%lld",i);
		}	
	}
		
	return 0;
}
