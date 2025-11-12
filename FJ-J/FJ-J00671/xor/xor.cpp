#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],pre[500010],t[500010],l,ans,y;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(t,-1,sizeof(t));
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=(pre[i-1]^a[i]);
	}
	t[0]=0;
	for (int i=1;i<=n;i++)
	{
		y=(pre[i]^k);
		if (t[y]!=-1 && t[y]+1>l)
		{
			l=i;ans++;
		}
		t[pre[i]]=i;
	}
	cout<<ans;
	return 0;
}

