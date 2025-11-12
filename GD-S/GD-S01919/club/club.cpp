#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T;
int n;
int a[N][3];
int id[N],cnt[3];
int w[N],cntw;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cnt[0]=cnt[1]=cnt[2]=0;
		cntw=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])cnt[0]++,id[i]=0,ans+=a[i][0];
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])cnt[1]++,id[i]=1,ans+=a[i][1];
			else cnt[2]++,id[i]=2,ans+=a[i][2];
		}
		if(cnt[0]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(id[i]==0)
					w[++cntw]=a[i][0]-max(a[i][1],a[i][2]);
			sort(w+1,w+1+cntw);
			for(int i=1;i<=cnt[0]-n/2;i++)ans-=w[i];
			cout<<ans<<'\n';
		}
		else if(cnt[1]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(id[i]==1)
					w[++cntw]=a[i][1]-max(a[i][0],a[i][2]);
			sort(w+1,w+1+cntw);
			for(int i=1;i<=cnt[1]-n/2;i++)ans-=w[i];
			cout<<ans<<'\n';
		}
		else if(cnt[2]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(id[i]==2)
					w[++cntw]=a[i][2]-max(a[i][0],a[i][1]);
			sort(w+1,w+1+cntw);
			for(int i=1;i<=cnt[2]-n/2;i++)ans-=w[i];
			cout<<ans<<'\n';
		}
		else cout<<ans<<'\n';
	}
	
	return 0;
}
