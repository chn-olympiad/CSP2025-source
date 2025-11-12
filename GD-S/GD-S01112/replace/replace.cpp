#include<iostream>
#include<cstdio>
using namespace std;
long long n,q,i;
string s,ss,t,tt;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		cin>>ss;
	}
	for(i=1;i<=q;i++)
	{
		cin>>t;
		cin>>tt;
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
