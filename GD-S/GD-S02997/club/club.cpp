#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,cnt[5],ans,a[N+5][5],v[N+5];
struct st
{
	int id,from,to,jian;
};
vector<st>cl;
bool cop(st x,st y)
{
	if(x.jian==y.jian) return a[x.id][x.from]<a[y.id][y.from];
	return x.jian<y.jian;
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
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) cnt[1]++,v[i]=1;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) cnt[2]++,v[i]=2;
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) cnt[3]++,v[i]=3;
		}
		if(cnt[1]>n/2)
		{
			cl.clear();
			for(int i=1;i<=n;i++)
			{
				if(v[i]==1) cl.push_back({i,1,2,a[i][1]-a[i][2]}),cl.push_back({i,1,3,a[i][1]-a[i][3]}); 
			}
			sort(cl.begin(),cl.end(),cop);
			for(int i=0;i<cl.size();i++)
			{
				if(v[cl[i].id]==1&&cnt[cl[i].to]<n/2)
				{
					v[cl[i].id]=cl[i].to;
					cnt[1]--;cnt[cl[i].to]++;
				}
				if(cnt[1]<=n/2) break;
			}
		}
		else if(cnt[2]>n/2)
		{
			cl.clear();
			for(int i=1;i<=n;i++)
			{
				if(v[i]==2) cl.push_back({i,2,1,a[i][2]-a[i][1]}),cl.push_back({i,3,1,a[i][2]-a[i][3]}); 
			}
			sort(cl.begin(),cl.end(),cop);
			for(int i=0;i<cl.size();i++)
			{
				if(v[cl[i].id]==2&&cnt[cl[i].to]<n/2)
				{
					v[cl[i].id]=cl[i].to;
					cnt[2]--;cnt[cl[i].to]++;
				}
				if(cnt[2]<=n/2) break;
			}
		}
		else if(cnt[3]>n/2)
		{
			cl.clear();
			for(int i=1;i<=n;i++)
			{
				if(v[i]==3) cl.push_back({i,3,2,a[i][3]-a[i][2]}),cl.push_back({i,3,1,a[i][3]-a[i][1]}); 
			}
			sort(cl.begin(),cl.end(),cop);
			for(int i=0;i<cl.size();i++)
			{
				if(v[cl[i].id]==3&&cnt[cl[i].to]<n/2)
				{
					v[cl[i].id]=cl[i].to;
					cnt[3]--;cnt[cl[i].to]++;
				}
				if(cnt[3]<=n/2) break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(v[i]==1) ans+=a[i][1];
			else if(v[i]==2) ans+=a[i][2];
			else ans+=a[i][3];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
