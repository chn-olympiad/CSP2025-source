#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	string s;
	cin>>s;
	long long n=1e9;
	long long a[n];
	for(int i=0;i<s.length();i++)
	{
		a[i]=s[i];
		if(a[i]>a[i-1])
			a[i]=a[i-1];
	}
	cout<<a;
	return 0;
}
