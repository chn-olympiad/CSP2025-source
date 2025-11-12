#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N][4],cnt[4],id[N],id_[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
		int n,ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		const int nn=n/2;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++)
		{
			int s1=-1,s2=-1;
			for(int j=1;j<=3;j++)
				if(a[i][j]>s1)
				{
					s1=a[i][j];
					id[i]=j;
				}
			for(int j=1;j<=3;j++)
				if(j!=id[i]&&a[i][j]>s2)
				{
					s2=a[i][j];
					id_[i]=j;
				}
			cnt[id[i]]++;
		}
		for(int i=1;i<=n;i++)
        {
			ans+=a[i][id[i]];
			if(cnt[id[i]]>nn)
                q.push(make_pair(a[i][id[i]]-a[i][id_[i]],i));
        }
		for(int i=1;i<=3;i++)
            while(cnt[i]>nn)
			{
				pair<int,int>p=q.top();
				q.pop();
				ans-=p.first;
				cnt[i]--;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
