#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[200200],b[200200],q11[200200],q2[200200];
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",&a[i],&b[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s%s",&q11[i],&q2[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int lkll=q11[i].size();
		int jkj=min(lkll,n);
		jkj/=3;
		cout<<jkj<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}