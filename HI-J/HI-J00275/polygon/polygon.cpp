#include<bits/stdc++.h>
using namespace std;
int ans;
int n;
int a[5005];
int maxn,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(sum>maxn*2)
	{
		ans++;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

