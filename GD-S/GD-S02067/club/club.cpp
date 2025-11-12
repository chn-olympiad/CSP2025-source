#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,sum,ans,cnt[4],gx[100005];
vector<pair<int,int> >vx,fx;
struct node{
	int a,b,c;
}a[100005];
bool cmp(pair<int,int>x,pair<int,int>y){return x>y;}
void Main()
{
	cin>>n;
	ans=0,cnt[1]=0,cnt[2]=0,cnt[3]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b>>a[i].c;
		vx.clear();
		vx.push_back({-a[i].a,1});
		vx.push_back({-a[i].b,2});
		vx.push_back({-a[i].c,3});
		sort(vx.begin(),vx.end());
//		cout<<-vx[0].first<<" "<<vx[0].second<<"\n";
		ans-=vx[0].first;
		gx[i]=vx[0].second;
		cnt[vx[0].second]++;
	}
	int ps=-1;
	for(int i=1;i<=3;i++)
		if(cnt[i]>n/2)
		{
			ps=i;
			break;
		}
	if(ps==-1)
	{
		cout<<ans<<"\n";
		return;
	}
//	cout<<ps<<" "<<cnt[ps]<<" Ps\n";
	fx.clear();
	for(int i=1;i<=n;i++)
		if(gx[i]==ps)
		{
			vx.clear();
			vx.push_back({-a[i].a,1});
			vx.push_back({-a[i].b,2});
			vx.push_back({-a[i].c,3});
			sort(vx.begin(),vx.end());
			fx.push_back({-vx[0].first+vx[1].first,i});
//			cout<<-vx[0].first+vx[1].first<<" "<<i<<"\n";
		}
	sort(fx.begin(),fx.end());
	for(int i=0;i<(int)fx.size();i++)
	{
		cnt[ps]--;
		vx.clear();
		vx.push_back({-a[fx[i].second].a,1});
		vx.push_back({-a[fx[i].second].b,2});
		vx.push_back({-a[fx[i].second].c,3});
		sort(vx.begin(),vx.end());
		cnt[vx[1].second]++;
		ans+=vx[0].first-vx[1].first;
//		cout<<fx[i].second<<" "<<vx[0].first-vx[1].first<<" "<<cnt[ps]<<"\n";
		if(cnt[ps]<=n/2)
			break;
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)Main();
	return 0;
}
