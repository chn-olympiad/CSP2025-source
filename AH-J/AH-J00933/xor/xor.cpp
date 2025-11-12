#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,a[N],k,dp[N],r1,ans,cnt;
struct node{
	int l,r;
}m[N];
bool cmp(node x,node y)
{
	return x.r<y.r;
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],dp[i]=dp[i-1]^a[i];
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			long long sum=dp[i-1]^dp[j];
			if(sum==k)m[++ans].l=i,m[ans].r=j;
		}
	}
	sort(m+1,m+ans+1,cmp);
	for(int i=1;i<=ans;i++)
	{
		if(m[i].l>r1)cnt++,r1=m[i].r;
	}
	cout<<cnt;
	return 0;
}
