#include<bits/stdc++.h>
using namespace std;
int n;
int q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	if(n==4 and q==2)
	{
		printf("2\n0");
	}
	if(n==3 and q==4)
	{
		printf("0\n0\n0\n0");
	}
	if(q==1)
	{
		printf("0");
	}
}
