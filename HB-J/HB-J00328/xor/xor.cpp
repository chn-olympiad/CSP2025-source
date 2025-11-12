#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
long long cnt;
int p(int l,int r)
{
	int c=0;
	for(int i=l;i<=r;i++)c=c^a[i];
	return c;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int cnt=0,l=i;
		for(int j=i;j<=n;j++)
		{
			if(p(l,j)==k)cnt++;
			k=j+1;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
