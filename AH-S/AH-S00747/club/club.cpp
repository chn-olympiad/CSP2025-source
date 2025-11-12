#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
struct CLUB
{
	int m_a,m_id,t1;
}f[100005];
bool cmp(CLUB f1,CLUB f2)
{
	return f1.t1>f2.t1;
}
int cnt[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int ma=-1,maj,mi=1e9,mij;
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
				if(ma<a[i][j])
				{
					ma=a[i][j];
					maj=j;
				}
				if(mi>a[i][j])
				{
					mi=a[i][j];
					mij=j;
				}
			}
			ans+=ma;
			f[i].m_a=maj;
			f[i].m_id=3-maj-mij;
			f[i].t1=ma-a[i][f[i].m_id];
		}
		sort(f+1,f+n+1,cmp);
			memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)
		{
			cnt[f[i].m_a]++;
			if(cnt[f[i].m_a]>n/2)
			{
				cnt[f[i].m_a]--;
				cnt[f[i].m_id]++;
				ans-=f[i].t1;
			}
		}
		cout<<ans<<endl;
	}
}
