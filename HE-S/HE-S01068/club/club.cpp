#include<bits/stdc++.h>
using namespace std;
int T,n;
long long ans[7];
long long dp[100002];
long long maxst,aa,bb,cc;
struct stu
{
	int a1;
	int b1;
	int c1;
	int maxabc;
};
stu a[100002];
bool cmp(stu c,stu d)
{
	return c.maxabc>d.maxabc;
}
int dfs(int i,int maxa,int maxb,int maxc)
{
	if(i>=n)
	{
		return max(max(maxa,maxb),maxc);
	}
//	maxa=0;
//	maxb=0;
//	maxc=0;
	if(aa<=maxst)
	{
		maxa=dfs(i+1,maxa+a[i].a1,maxb,maxc);
		aa++;
	}
	if(bb<=maxst)
	{
		maxb=dfs(i+1,maxa,maxb+a[i].b1,maxc);
		bb++;
	}
	if(cc<=maxst)
	{
		maxc=dfs(i+1,maxa,maxb,maxc+a[i].c1);
		cc++;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int l=0;l<T;l++)
	{
		cin>>n;
		maxst=n>>1;
		aa=0;
		bb=0;
		cc=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].b1>>a[i].c1;
			a[i].maxabc=max(max(a[i].a1,a[i].b1),a[i].c1);
		}
		sort(a+1,a+n+1,cmp);
//		cout<<dfs(1,0,0,0)<<"----------";
//		for(int i=1;i<=n;i++)
//		{
//			cout<<a[i].a1<<a[i].b1<<a[i].c1<<endl;
////			a[i].maxabc=max(max(a[i].a1,a[i].b1),a[i].c1);
//		}
		for(int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1]+a[i].maxabc;
			if(a[i].a1==a[i].maxabc)
			{
				if(aa<=maxst)
				{
					aa++;
				}
				else
				{
					dp[i]=dp[i-1];
					if(a[i].b1>=a[i].c1)
					{
						if(bb<=maxst)
						{
							dp[i]=dp[i-1]+a[i].b1;
							bb++;
						}
						else if(cc<=maxst)
						{
							dp[i]=dp[i-1]+a[i].c1;
							cc++;
						}
					}
					else
					{
						if(cc<=maxst)
						{
							dp[i]=dp[i-1]+a[i].c1;
							cc++;
						}
						else if(bb<=maxst)
						{
							dp[i]=dp[i-1]+a[i].b1;
							bb++;
						}
					}
				}
			}
			else if(a[i].b1==a[i].maxabc)
			{
				if(bb<=maxst)
				{
					bb++;
				}
				else
				{
					dp[i]=dp[i-1];
					if(a[i].a1>=a[i].c1)
					{
						if(aa<=maxst)
						{
							dp[i]=dp[i-1]+a[i].a1;
							aa++;
						}
						else if(cc<=maxst)
						{
							dp[i]=dp[i-1]+a[i].c1;
							cc++;
						}
					}
					else
					{
						if(cc<=maxst)
						{
							dp[i]=dp[i-1]+a[i].c1;
							cc++;
						}
						else if(aa<=maxst)
						{
							dp[i]=dp[i-1]+a[i].a1;
							aa++;
						}
					}
				}
			}
			else if(a[i].c1==a[i].maxabc)
			{
				if(cc<=maxst)
				{
					cc++;
				}
				else
				{
					dp[i]=dp[i-1];
					if(a[i].b1>=a[i].a1)
					{
						if(bb<=maxst)
						{
							dp[i]=dp[i-1]+a[i].b1;
							bb++;
						}
						else if(aa<=maxst)
						{
							dp[i]=dp[i-1]+a[i].a1;
							aa++;
						}
					}
					else
					{
						if(aa<=maxst)
						{
							dp[i]=dp[i-1]+a[i].a1;
							aa++;
						}
						else if(bb<=maxst)
						{
							dp[i]=dp[i-1]+a[i].b1;
							bb++;
						}
					}
				}
			}	
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
