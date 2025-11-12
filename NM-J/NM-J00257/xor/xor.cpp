#include<bits/stdc++.h>
using namespace std;
int a[500100],qz[500100];
int gt(int l,int r)
{
	unsigned int la=qz[l-1],ra=qz[r],rt=0,i;
	for(i=1;i<=22;i++)
	{
		if(ra<<(32-i)>>31==1) rt+=!(la<<(32-i)>>31)<<(i-1);
		else rt+=(la<<(32-i)>>31)<<(i-1);
	}
	return rt;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,j,ans=0,lt=1;
	cin>>n>>k;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	qz[1]=a[1];
	for(i=2;i<=n;i++) qz[i]=a[i]^qz[i-1];
	for(i=1;i<=n;i++)
	{
		for(j=lt;j<=i;j++)
		{
			if(gt(j,i)==k)
			{
				lt=i+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
