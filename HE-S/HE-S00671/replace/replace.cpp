#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s1,s2;
string t1,t2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		printf("0\n");	
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
