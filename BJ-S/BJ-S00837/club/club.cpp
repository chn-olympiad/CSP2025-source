#include<bits/stdc++.h>
using namespace std;
struct Node 
{
	int l,r;
};
int a[50],b[50],c[50],dp[50][50][50][50],n;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=0 || c[i]!=0) return 0;
	}
	return 1;
}
bool cmp(Node aa,Node bb)
{
	return aa.l-aa.r>bb.l-bb.r;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n<=30)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int yi=0;yi<=min(n/2,i);yi++)
				{
					for(int er=0;er<=min(n/2,i);er++)
					{
						int san=i-yi-er;
						if(san<0 || san>n/2) continue;
						dp[i][yi][er][san]=0;
						if(yi>0)dp[i][yi][er][san]=max(dp[i][yi][er][san],dp[i-1][yi-1][er][san]+a[i]);
						if(er>0)dp[i][yi][er][san]=max(dp[i][yi][er][san],dp[i-1][yi][er-1][san]+b[i]);
						if(san>0)dp[i][yi][er][san]=max(dp[i][yi][er][san],dp[i-1][yi][er][san-1]+c[i]);
						if(i==n) ans=max(ans,dp[i][yi][er][san]);
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(check())
		{
			sort(a+1,a+n+1);
			int ans=0;
			for(int i=n;i>n/2;i--) ans+=a[i];
			cout<<ans<<endl;
		}
		else
		{
			int ans=0;
			vector<Node> A,B;
			for(int i=1;i<=n;i++)
			{
				if(a[i]>b[i]) A.push_back({a[i],b[i]});
				else if(b[i]>a[i]) B.push_back({b[i],a[i]});
			}
			if(A.size()<B.size())
			{
				for(int i=0;i<(int)A.size();i++) ans+=A[i].l;
				sort(B.begin(),B.end(),cmp);
				for(int i=0;i<min(n/2,(int)B.size());i++) ans+=B[i].l;
				for(int i=n/2;i<(int)B.size();i++) ans+=B[i].r;
			}
			else
			{
				for(int i=0;i<(int)B.size();i++) ans+=B[i].l;
				sort(A.begin(),A.end(),cmp);
				for(int i=0;i<min(n/2,(int)A.size());i++) ans+=A[i].l;
				for(int i=n/2;i<(int)A.size();i++) ans+=A[i].r;
			}
			cout<<ans;
		}
	}
	return 0;
}
