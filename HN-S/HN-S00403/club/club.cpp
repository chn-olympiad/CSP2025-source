#include<bits/stdc++.h>
using namespace std;
long long t,n,ans=0,A=1,v[100007];
struct N{
	long long x,id;
}a[100007],b[100007],c[100007];
bool cmp(N x,N y)
{
	return x.x>y.x;
}
void dfs(int x,long long sum1,long long sum2,long long sum3,long long cnt1,long long cnt2,long long cnt3)
{
	if(cnt1>n/2 || cnt2>n/2 || cnt3>n/2)
	{
		return ;
	}
	if(x>n)
	{
		ans=max(ans,sum1+sum2+sum3);
		return ;
	}
	dfs(x+1,sum1+a[x].x,sum2,sum3,cnt1+1,cnt2,cnt3);
	dfs(x+1,sum1,sum2+b[x].x,sum3,cnt1,cnt2+1,cnt3);
	dfs(x+1,sum1,sum2,sum3+c[x].x,cnt1,cnt2,cnt3+1);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0ll;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			v[i]=0;
			cin>>a[i].x>>b[i].x>>c[i].x;
			if(b[i].x!=0 || c[i].x!=0)
			{
				A=0;
			}
		}
		if(A==1)
		{
			sort(a+1,a+1+n,cmp);
			long long sum=0;
			for(int i=n/2;i<=n;i++)
			{
				sum+=a[i].x;
			}
			cout<<sum;
		}
		else if(n<=30)
		{
			dfs(1,0ll,0ll,0ll,0ll,0ll,0ll);
			cout<<ans<<"\n";
		}
//		else
//		{
//			sort(a+1,a+1+n,cmp);
//			sort(b+1,b+1+n,cmp);
//			sort(c+1,c+1+n,cmp);
//			for(int i=1;i<=n;i++)
//			{
//				if(v[i]==0)
//				{
//					
//				}
//			}
//		}
	}
	return 0;
}
