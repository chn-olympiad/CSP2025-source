#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i = 1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
	}
	for(long long i = 1;i<=q;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())cout<<0<<"\n";
		else
		{
			cout<<1<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
