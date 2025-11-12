#include<bits/stdc++.h>
using namespace std;
struct aaa
{
	int xx,num;
}a[4];
struct aaaa
{
	int x,y,z,sum;
}b[100010];
bool cmp(aaa a1,aaa a2)
{
	return a1.xx>a2.xx;
}
bool cmp1(aaaa a1,aaaa a2)
{
	return a1.sum>a2.sum;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		int x,y,z,sum[4]={},dp[100010]={},temp,n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>b[i].x>>b[i].y>>b[i].z;
			b[i].sum=b[i].x+b[i].y+b[i].z;
		}
		sort(b+1,b+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			a[1].num=1;a[1].xx=b[i].x;a[2].num=2;a[2].xx=b[i].y;
			a[3].num=3;a[3].xx=b[i].z;sort(a+1,a+4,cmp);
			if(sum[a[1].num]<n/2)
			{
				dp[i]=dp[i-1]+=a[1].xx;
				sum[a[1].num]++;
			}
			else if(sum[a[2].num]<n/2)
			{
				dp[i]=dp[i-1]+=a[2].xx;
				sum[a[2].num]++;
			}
			else
			{
				dp[i]=dp[i-1]+=a[3].xx;
				sum[a[3].num]++;
			}
		}
		cout<<dp[n]<<"\n";
	}
	return 0;
}