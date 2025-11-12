#include<bits/stdc++.h>
using namespace std;
int a1[100005],a2[100005],a3[100005],a1_id[50005],a2_id[50005],a3_id[50005],pre[50005];
void solve()
{
	int n,cnt_a1,cnt_a2,cnt_a3,min_a1,min_a2,min_a3,ans=0;
	cnt_a1=cnt_a2=cnt_a3=0;
	min_a1=min_a2=min_a3=20005;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a1[i]>>a2[i]>>a3[i];
		int maxn=max(a1[i],max(a2[i],a3[i]));
		if(a1[i]>a2[i]&&a1[i]>a3[i])
		{
			pre[i]=maxn-max(a2[i],a3[i]);
		} else if(a2[i]>a1[i]&&a2[i]>a3[i])
		{
			pre[i]=maxn-max(a1[i],a3[i]);
		}
		else
		{
			pre[i]=maxn-max(a2[i],a1[i]);
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(a1[i]>a2[i]&&a1[i]>a3[i])
		{
			if(cnt_a1*2==n)
			{
				if(pre[i]>min_a1)
				{
					--cnt_a1;
					ans-=min_a1;
					min_a1=pre[a1_id[1]];
					for(int i=2;i<=cnt_a1;++i)
					{
						min_a1=min(min_a1,pre[a1_id[i]]);
					}
				}
				else
				{
					ans+=max(a2[i],a3[i]);
					continue;
				}
			}
			++cnt_a1;
			a1_id[cnt_a1]=pre[i];
			ans+=a1[i];
			if(pre[i]<min_a1)
			{
				min_a1=pre[i];
			}
		} else if(a2[i]>a3[i]&&a2[i]>a1[i])
		{
			if(cnt_a2*2==n)
			{
				if(pre[i]>min_a2)
				{
					--cnt_a2;
					ans-=min_a2;
					for(int i=2;i<=cnt_a2;++i)
					{
						min_a2=min(min_a2,pre[a2_id[i]]);
					}
				}
				else
				{
					ans+=max(a1[i],a3[i]);
					continue;
				}
			}
			++cnt_a2;
			a2_id[cnt_a2]=pre[i];
			ans+=a2[i];
			if(pre[i]<min_a2)
			{
				min_a2=pre[i];
			}
		} else
		{
			if(cnt_a3*2==n)
			{
				if(pre[i]>min_a3)
				{
					--cnt_a3;
					ans-=min_a3;
					for(int i=2;i<=cnt_a3;++i)
					{
						min_a3=min(min_a3,pre[a3_id[i]]);
					}
				}
				else
				{
					ans+=max(a1[i],a2[i]);
					continue;
				}
			}
			++cnt_a3;
			a3_id[cnt_a3]=pre[i];
			ans+=a3[i];
			if(pre[i]<min_a3)
			{
				min_a3=pre[i];
			}
		}
	}
	cout<<ans<<"\n";
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
