#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char x;
	cin>>s;
	long long n=s.size()+5;
	long long a[n];
	long long k=0;
	for(long long i=0;i<s.size() ;i++)
	{
		if(isdigit(s[i]))
		{
			x=s[i];
			a[k]=int(x)-48;
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(long long i=0;i<k;i++)
	cout<<a[i];
	return 0;
}
