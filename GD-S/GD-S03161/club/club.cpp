#include<bits/stdc++.h>
#define fin(x) freopen(#x".in","r",stdin)
#define fout(x) freopen(#x".out","w",stdout)
#define fans(x) freopen(#x".ans","w",stdout)
const int N=1e5+7; 
using namespace std;
int n,cnt[3],b[N],ans;
vector<pair<int,int>>a[N];
priority_queue<int>que[3];
void solve()
{
	for(int i = 1;i<= n;i++)a[i].clear();
	for(int i = 0;i< 3;i++)
	{
		cnt[i]=0;
		while(que[i].size())que[i].pop();
	}
	ans=0;
	cin>>n;
	for(int i = 1,x,y,z;i<= n;i++)
	{
		cin>>x>>y>>z;
		a[i].emplace_back(x,0);
		a[i].emplace_back(y,1);
		a[i].emplace_back(z,2);
		sort(a[i].begin(),a[i].end());
		cnt[a[i][2].second]++,b[i]=a[i][2].first-a[i][1].first;
		ans+=a[i][2].first;
		que[a[i][2].second].push(-b[i]);
	}
	int k=-1;
	for(int i = 0;i< 3;i++)if(cnt[i]>(n/2))k=i;
	if(k==-1)
	{
		cout<<ans<<'\n';
		return;
	}
	while(cnt[k]>(n/2))
	{
		cnt[k]--;
		int x=-que[k].top();
		que[k].pop();
		ans-=x;
	}
	cout<<ans<<'\n';
}

int main()
{
//	fin(club5);
//	fout(club5);
//	fin(club);
//	fout(club);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
