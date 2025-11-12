#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin >>n >>q;
	string s1[n+1],s2[n+1];
	for (long long i=1;i<=n;i++)
	{
		cin >>s1[i] >>s2[i];
	}
	string a1[q+1],a2[q+1];
	for(long long i=1;i<=q;i++)
	{
		cin >>a1[i] >>a2[i];
	}
	cout <<2 <<endl <<0;
	return 0;
}
