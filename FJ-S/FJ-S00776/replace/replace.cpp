#include<bits/stdc++.h>
using namespace std;
int n,q,ans[210000];
string s1[210000],s2[210000],c1,c2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	  cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)
	{
		cin>>c1>>c2;
	}
	for(int i=1;i<=n;i++)
	  printf("%d\n",ans[i]);
	return 0;
}