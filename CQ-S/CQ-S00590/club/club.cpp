#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][3],id[N],cnt[3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>T;
	while(T--)
	{
		cin>>n,cnt[0]=cnt[1]=cnt[2]=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int mx=0;
			for(int j=0;j<3;j++)cin>>a[i][j],mx=max(mx,a[i][j]);
			ans+=mx;
			for(int j=0;j<3;j++)if(a[i][j]==mx)id[i]=j;
			cnt[id[i]]++;
		}
		for(int i=0;i<3;i++)if(cnt[i]>n/2)
		{
			vector<pair<int,int>>v;
			for(int j=1;j<=n;j++)if(id[j]==i)
			{
				int mx1=0;
				for(int k=0;k<3;k++)if(i!=k)mx1=max(mx1,a[j][k]);
				v.emplace_back(a[j][i]-mx1,j);
			}
			sort(v.begin(),v.end());
			for(auto j:v)
			{
				ans-=j.first,cnt[i]--;
				if(cnt[i]==n/2)break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

