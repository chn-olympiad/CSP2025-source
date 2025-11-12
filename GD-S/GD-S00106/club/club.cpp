#include <bits/stdc++.h>
using namespace std;
int a[100007][3];
pair<int,int> p[100007];
vector<pair<int,int> > r[3];
int vis[100007];
int cmp(pair<int,int> a,pair<int,int> b)
{
	return a.first>b.first;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,ans=0;
		cin>>n;
		int cnt0=n/2,cnt1=n/2,cnt2=n/2;
		for(int i=0;i<n;i++)
		{
			vis[i]=0;
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		r[0].clear(),r[1].clear(),r[2].clear();
		for(int i=0;i<n;i++)
		{
			if(a[i][0]>=a[i][1])
			{
				if(a[i][1]>=a[i][2]) p[i]=make_pair(0,1);
				else
				{
					if(a[i][0]>=a[i][2]) p[i]=make_pair(0,2);
					else p[i]=make_pair(2,0);
				}
			}else{
				if(a[i][0]>=a[i][2]) p[i]=make_pair(1,0);
				else
				{
					if(a[i][1]>=a[i][2]) p[i]=make_pair(1,2);
					else p[i]=make_pair(2,1);
				}
			}
			r[p[i].first].push_back(make_pair(a[i][p[i].first],i));
		}
		int sct=-1;
		if(r[0].size()>n/2) sct=0;
		if(r[1].size()>n/2) sct=1;
		if(r[2].size()>n/2) sct=2;
		if(sct==-1)
		{
			for(int i=0;i<n;i++) ans+=a[i][p[i].first];
		}else{
			sort(r[sct].begin(),r[sct].end(),cmp);
			for(int i=0;i<r[sct].size();i++) vis[r[sct][i].second]=1;
			priority_queue<pair<int,int> > better;
			priority_queue<pair<int,int> > worse;
			for(int i=0;i<n/2;i++) ans+=r[sct][i].first,better.push(make_pair(-r[sct][i].first+a[r[sct][i].second][p[r[sct][i].second].second],r[sct][i].second));
			for(int i=n/2;i<r[sct].size();i++) ans+=a[r[sct][i].second][p[r[sct][i].second].second],worse.push(make_pair(-a[r[sct][i].second][p[r[sct][i].second].second]+r[sct][i].first,r[sct][i].second));
			while(!worse.empty())
			{
				if(worse.top().first+better.top().first<=0) break;
				ans+=worse.top().first+better.top().first;
				better.pop();
				worse.pop();
			}
			for(int i=0;i<n;i++) if(!vis[i]) ans+=a[i][p[i].first];
		}
		cout<<ans<<endl;
	}
	return 0;
}
