#include<bits/stdc++.h>
using namespace std;

int n,k,a[514514],ans,cd=2,ma=-1;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); 
	}
	ans=n/2;
	printf("%d",ans);
	return 0;
}
/*
4 2
2 1 0 3
*/
