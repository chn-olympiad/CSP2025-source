#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],f=0;
int ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1) f=1;
	}
	if(k&&f)
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i-1]) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
