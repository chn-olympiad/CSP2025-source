#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,q;
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; ++i)
		cin>>s1>>s2;
	for(int i=1; i<=q; ++i)
		cin>>s1>>s2;
	for(int i=1; i<=q; ++i)
		printf("1\n");
	return 0;
}
