#include<bits/stdc++.h>
using namespace std;
int readin()
{
	char st;
	int res=0;
	st=getchar();
	while(st>='0'&&st<='9')
	{
		res=res*10+st-'0';
		st=getchar();
	}
	return res;
}
int n,k;
int a[500005];
int sum[500005];
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=readin();
	k=readin();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int s=0;
	for(int i=1;i<=n;i++)
	{
		if((sum[i]^sum[s])==k)
		{
			s=i;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}