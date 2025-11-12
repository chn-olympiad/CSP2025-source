#include<bits/stdc++.h>
using namespace std;
int a[100005][5],zg[100005],cg[100005],cnt[5],cz[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(zg,0,sizeof(zg));
		memset(cg,0,sizeof(cg));
		memset(cnt,0,sizeof(cnt));
		memset(cz,0,sizeof(cz));
		int n,ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if (a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) 
			{
				zg[i]=1;
				if (a[i][2]>=a[i][3]) cg[i]=2;
				else cg[i]=3;
			}
			else if (a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) 
			{
				zg[i]=2;
				if (a[i][1]>=a[i][3]) cg[i]=1;
				else cg[i]=3;
			}
			else 
			{
				zg[i]=3;
				if (a[i][1]>=a[i][2]) cg[i]=1;
				else cg[i]=2;
			}
			ans+=a[i][zg[i]];
			cnt[zg[i]]++;
		}
		int xx,len=0;
		if (cnt[1]==max(max(cnt[1],cnt[2]),cnt[3])) xx=1;
		else if (cnt[2]==max(max(cnt[1],cnt[2]),cnt[3])) xx=2;
		else xx=3;
		for (int i=1;i<=n;i++)
		{
			if (zg[i]==xx)
			{
				cz[++len]=a[i][zg[i]]-a[i][cg[i]];
			}
		}
		sort(cz+1,cz+len+1);
		if (max(max(cnt[1],cnt[2]),cnt[3])>n/2)
		{
			int x=max(max(cnt[1],cnt[2]),cnt[3])-n/2;
			for (int i=1;i<=x;i++) ans-=cz[i];
		}
		cout<<ans<<endl;
	}	
	return 0;
}
