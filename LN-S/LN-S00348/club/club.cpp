#include<bits/stdc++.h>
using namespace std;
int n,a[200005][4],cnt[4],maxx[200005],b[200005],tot,ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(maxx,0,sizeof(maxx));
		memset(cnt,0,sizeof(cnt));
		ans=0;
		tot=0;
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				cnt[1]++;
				maxx[i]=1;
			}
			else if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1])
			{
				cnt[2]++;
				maxx[i]=2;
			}
			else
			{
				cnt[3]++;
				maxx[i]=3;
			}
		}
		int qwq=0;
		if(cnt[1]>=cnt[2]&&cnt[1]>=cnt[3]) qwq=1;
		else if(cnt[2]>=cnt[1]&&cnt[2]>=cnt[3]) qwq=2;
		else qwq=3;
		for(int i=1;i<=n;i++) ans+=a[i][maxx[i]];
		if(cnt[qwq]<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				sort(a[i]+1,a[i]+3+1);
				if(maxx[i]==qwq)
				{
					b[++tot]=a[i][3]-a[i][2];
				}
			}
			sort(b+1,b+tot+1);
			for(int i=1;i<=tot;i++)
			{
				ans-=b[i];
				cnt[qwq]--;
				if(cnt[qwq]==n/2) break;
			}
			cout<<ans<<endl;
		}
	}
}
