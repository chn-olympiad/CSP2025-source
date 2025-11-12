#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans=0;
int main()
{
	freopen("xor1.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d\n",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d ",a+i);
	if(k==0)
	{
		for(int i=1;i<=n;i++) if(a[i]==0) ans++;
		printf("%d",ans);
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++) if(a[i]%2==1) ans++;
		int sum=n-ans;
		printf("%d",ans+ans*sum);
	}
	return 0;
}



