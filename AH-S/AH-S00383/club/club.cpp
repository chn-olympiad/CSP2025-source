#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,t,o,o2,o3;
int a[100005][5];
int x1[100005],x2[100005],x3[100005];
bool cmp(int A,int B)
{
	return A>B;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==2)
		{
			cin>>a[1][1]>>a[1][2]>>a[1][3]>>a[2][1]>>a[2][2]>>a[2][3];
			int maxn=max({a[1][1],a[1][2],a[1][3]});
			int maxn2=max({a[2][1],a[2][2],a[2][3]});
			int d1=0,d2=0;
			if(maxn==a[1][1])
				d1=1;
			if(maxn==a[1][2])
				d1=2;
			if(maxn==a[1][3])
				d1=3;
			if(maxn2==a[2][1])
				d2=1;
			if(maxn2==a[2][2])
				d2=2;
			if(maxn2==a[2][3])
				d2=3;
			bool flag=0;
			if(d1!=d2)
			{
				//cout<<d1<<" "<<d2<<"\n";
				cout<<maxn+maxn2<<"\n";
				flag=1;
			}
			if(flag==1)continue;
			int ans1=0,ans2=0;
			for(int i=1;i<=3;i++)
			{
				if(i!=d1)
					ans1=max(ans1,a[1][i]);
			}
			for(int i=1;i<=3;i++)
			{
				if(i!=d2)
					ans2=max(ans2,a[2][i]);
			}
			//cout<<ans1<<" "<<maxn2<<" "<<ans2<<" "<<maxn<<"\n";
			int sum=max(ans1+maxn2,ans2+maxn);
			cout<<sum<<"\n";
		}
		else
		{
			for(int i=1;i<=n;i++)
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			for(int i=1;i<=n;i++)
				x1[++o]=a[i][1];
			for(int i=1;i<=n;i++)
				x2[++o2]=a[i][2];
			for(int i=1;i<=n;i++)
				x3[++o3]=a[i][3];
			sort(x1+1,x1+1+o,cmp);
			sort(x2+1,x2+1+o2,cmp);
			sort(x3+1,x3+1+o3,cmp);
			int sum=0,sum2=0,sum3=0;
			for(int i=1;i<=n/2;i++)
				sum+=x1[i],sum2+=x2[i],sum3+=x3[i];
			cout<<max({sum,sum2,sum3})<<"\n";
		}
	}
	return 0;
}
