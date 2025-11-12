#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=1e5+10;
int n;
struct node{
	int my[4];
	int m,lm,lk;
};
node a[N];
vector<int> b[4];
ll ans;
void solve1(int k)
{
	priority_queue<int,vector<int>,greater<int>> v1;
	for(int i=0;i<b[k].size();i++)
	{
		v1.push(a[b[k][i]].m-a[b[k][i]].lm);
	}
	int now=b[k].size();
	while(now>(n/2))
	{
		int x=v1.top();
		v1.pop();
		ans-=x;
		now--; 
	}
	return ;
}
void solve()
{
	memset(b,0,sizeof b);
	ans=0;
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].my[1]>>a[i].my[2]>>a[i].my[3];
		int maxx=0,k=0,lmaxx=0,lk=0;
		for(int j=1;j<=3;j++)
		{
			if(a[i].my[j]>=maxx)
			{
				if(maxx>=lmaxx)
				{
					lmaxx=maxx;
					lk=k;
				}
				maxx=a[i].my[j];
				k=j;
			}
			else if(a[i].my[j]>=lmaxx) 
			{
				lmaxx=a[i].my[j];
				lk=j;
			}
		}
		a[i].lk=lk;
		a[i].lm=lmaxx;
		a[i].m=maxx;
		b[k].push_back(i);
		ans+=maxx;
//		cout<<a[i].lm<<' ';
	}
	if(b[1].size()>(n/2))
	{
		solve1(1);
	}
	else if(b[2].size()>(n/2))
	{
		solve1(2);
	}
	else if(b[3].size()>(n/2))
	{
		solve1(3);
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		solve();	
	} 
	return 0;
} 