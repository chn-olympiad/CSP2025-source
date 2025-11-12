#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500050];
bool check(int x)
{
	int cnt=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		ans=(ans^a[i]);
		if(ans==k)
		{
			cnt++;
			ans=0;
			continue;
		}
		else continue;
	}
	return cnt>=x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	int l=1,r=5e6+5;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0; 
}