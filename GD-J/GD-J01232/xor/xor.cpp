#include<bits/stdc++.h>
using namespace std;
int aa[1000010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,c=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&aa[i]);
		if(aa[i]==b) c++;
		if(aa[i]!=b&&aa[i-1]!=b&&i-1>0)
		{
			aa[i]=b;
			c++;
		}
	}
	printf("%d",c);
	return 0;
}
