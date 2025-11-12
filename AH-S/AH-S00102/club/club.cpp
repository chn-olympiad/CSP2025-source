#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int N=1e5+5;
struct ch
{
	int c;
	int num;
};
bool cmp(ch a,ch b)
{
	return a.c>b.c;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int a[N][5];
		int sum[5];
		for(int i=0;i<=4;i++)
			sum[i]=0;
		vector<bool>f(5,1);
		ch cha[N];
		int n,ans=0;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=3;j++)
				a[i][j]=0;
		for(int i=1;i<=N;i++)
			cha[i].c=cha[i].num=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
		{
			cha[i].c=abs(a[i][1]-a[i][2])+abs(a[i][1]-a[i][3])+abs(a[i][2]-a[i][1])+abs(a[i][2]-a[i][3])+abs(a[i][3]-a[i][1])+abs(a[i][3]-a[i][2]);
			cha[i].num=i;
		}
		sort(cha+1,cha+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int k=cha[i].num;
			bool x=0,y=0,z=0;
			int mx=0;
			if(sum[1]<n/2)
			{
				mx=a[k][1];
				x=1;
			}
			if(sum[2]<n/2)
			{
				if(a[k][2]>mx)
				{
					mx=a[k][2];
					x=0,y=1;
				}
			}
			if(sum[3]<n/2)
			{
				if(a[k][3]>mx)
				{
					mx=a[k][3];
					x=0,y=0,z=1;
				}
			}
			if(x) sum[1]++;
			else if(y) sum[2]++;
			else if(z) sum[3]++;
			
			cout<<mx<<" "<<sum[1]<<" "<<sum[2]<<" "<<sum[3]<<"\n";
			ans+=mx;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
