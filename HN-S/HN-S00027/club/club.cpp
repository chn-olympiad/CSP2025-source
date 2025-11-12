#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int t,a[N][10],b[N],n,c[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int ans=0,cnt=0,s=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int num=0,sum=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>sum)
				{
					num=j;
					sum=a[i][j];
				}
			}
			c[num]++;
			s+=sum;
		}
		if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2)
		{
			cout<<s<<"\n";
			memset(a,0,sizeof a);
			memset(b,0,sizeof b);
			memset(c,0,sizeof c);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			b[i]=max(a[i][2],a[i][3])-a[i][1];
			cnt+=a[i][1];
		}
		sort(b+1,b+1+n);
		for(int i=n;i>n/2;i--)
			cnt+=b[i];
		ans=max(ans,cnt);
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			b[i]=max(a[i][1],a[i][3])-a[i][2];
			cnt+=a[i][2];
		}
		sort(b+1,b+1+n);
		for(int i=n;i>n/2;i--)
			cnt+=b[i];
		ans=max(ans,cnt);
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			b[i]=max(a[i][2],a[i][1])-a[i][3];
			cnt+=a[i][3];
		}
		sort(b+1,b+1+n);
		for(int i=n;i>n/2;i--)
			cnt+=b[i];
		ans=max(ans,cnt);
		cnt=0;
		cout<<ans<<"\n";
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
	}
	return 0;
}
