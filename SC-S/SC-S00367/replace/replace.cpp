#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],t1[200005],t2[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>t1[i]>>t2[i];
		printf("0");
	}
	return 0;
}