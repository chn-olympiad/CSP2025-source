#include<bits/stdc++.h>
using namespace std;
string a;
long long b[11],pos=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	for(long long i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[a[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--)
	{
		while(b[i]--)
		{
			cout<<i;
		}
	}
	return 0;
} 
