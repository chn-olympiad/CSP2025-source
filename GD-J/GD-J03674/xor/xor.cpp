#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt,ans,a[500010];int n,k;
bool v[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(v,0,sizeof v);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==k)cnt++,v[i]=1;
	}
	for(int i=1;i<=n;i++)if(!v[i])
	{
		ans=a[i];v[i]=1;
		for(int j=i+1;j<=n;j++)
		{
			if(v[j])break;
			ans^=a[j];v[j]=1;
			if(ans==k){cnt++;break;}
		}
	}
	printf("%lld\n",cnt);
	return 0;
}
