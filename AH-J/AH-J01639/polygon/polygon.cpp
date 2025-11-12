//polygon.cpp
#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5010],n;
int maxn(int l,int r)
{
	int ans=0;
	for(int i=l;i<=r;i++)
		if(a[i]>ans) ans=a[i];
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<3) puts("0");
	else
	{
		int num=0;
		for(int i=1;i<=n;i++)
			num+=a[i];
		if(num<=maxn(1,3)*2) puts("0");
		else puts("1");
	}
	return 0;
}
