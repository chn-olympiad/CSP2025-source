#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s=0,m=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s++;
	}
	s=s%m;
	printf("%d",s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
