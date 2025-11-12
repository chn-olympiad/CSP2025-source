#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++) scanf("%d ",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
		for(int j=i+1;j<=n-1;j++)
			for(int k=j+1;k<=n;k++)
				if(a[i]+a[j]>a[k]) ans++;
	printf("%ld",ans%998244353);
	return 0;
}


