//GZ-S00215 贵阳市第一中学  李啸峰 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int T,n,a[N][5],id1[N],id2[N],cnt[5],Ans,change[N],ch;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		Ans=ch=0;
		memset(a,0,sizeof a);
		memset(id1,0,sizeof id1);
		memset(id2,0,sizeof id2);
		memset(cnt,0,sizeof cnt);
		memset(change,0,sizeof change);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int best=max({a[i][1],a[i][2],a[i][3]});
			if(a[i][1]==best)
			{
				id1[i]=1;
				int better=max(a[i][2],a[i][3]);
				if(a[i][2]==better)
					id2[i]=2;
				else
					id2[i]=3;
			}
			else if(a[i][2]==best)
			{
				id1[i]=2;
				int better=max(a[i][1],a[i][3]);
				if(a[i][1]==better)
					id2[i]=1;
				else
					id2[i]=3;
			}
			else
			{
				id1[i]=3;
				int better=max(a[i][1],a[i][2]);
				if(a[i][1]==better)
					id2[i]=1;
				else
					id2[i]=2;
			}
			cnt[id1[i]]++;
		}
		for(int i=1;i<=n;i++)
			Ans+=a[i][id1[i]];
		int flag=0;
		for(int i=1;i<=3;i++)
			if(cnt[i]>n/2)
				flag=i;
		if(!flag)
		{
			cout<<Ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
			if(id1[i]==flag)
				change[++ch]=a[i][id1[i]]-a[i][id2[i]];
		sort(change+1,change+ch+1);
		for(int i=1;i<=ch-n/2;i++)
			Ans-=change[i];
		cout<<Ans<<endl;
	}
	return 0;
}
