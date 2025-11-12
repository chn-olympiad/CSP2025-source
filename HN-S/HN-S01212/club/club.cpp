#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+5;
int n;
struct nd{
	int x,y,z;
	bool operator<(nd y)	const 
	{
		return x > y.x;
	}
}a[N];
int ans = 0;
priority_queue<nd> pq[4];

int vis[4];

pair<int,int> getmax(nd x)
{
	if(x.x >= x.y && x.x >= x.z)	return {x.x,1};
	if(x.y >= x.x && x.y >= x.z)	return {x.y,2};
	if(x.z >= x.x && x.z >= x.y)	return {x.z,3};
}

pair<int,int> getminer(nd x,int dx)
{
	int res = -800,ind = 0;
	int maxn = 0;
	maxn = (dx == 1 ? x.x : (dx == 2 ? x.y : x.z));
	if(x.x <= maxn && x.x >= res && dx != 1 && vis[1] < n/2)	res = x.x,ind=1;
	if(x.y <= maxn && x.y >= res && dx != 2 && vis[2] < n/2)	res = x.y,ind=2;
	if(x.z <= maxn && x.z >= res && dx != 3 && vis[3] < n/2)	res = x.z,ind=3;
	return {res,ind};
}

bool solve(pair<int,int> t,int i,bool mst)
{
	if(vis[t.second] < n/2)
	{
		vis[t.second]++;
		pq[t.second].push({t.first-getminer(a[i],t.second).first,t.second,i});
		ans += t.first;
		return 1;
	}
	else
	{
		nd t1 = pq[t.second].top();
		pair<int,int> vr = getminer(a[t1.z],t1.y);
		if(vr.first == -800)	return 0;
		if(t1.x < t.first || mst)
		{
			if(!mst && t1.x > t.first - getminer(a[i],t.second).first)	return 0;
			
			pq[t.second].pop();
			pq[vr.second].push({vr.first,vr.second,t1.z});
			pq[t.second].push({t.first-getminer(a[i],t.second).first,t.second,i});
			
//			cout<<ans<<' '<<i<<' '<<t.first<<' '<<vr.first<<' '<<t1.x<<endl;
			
			ans += t.first - t1.x;
			vis[vr.second]++;
			return 1;
		}
		return 0;
	}
	
	return 0;
}

void init()
{
	vis[1]=vis[2]=vis[3]=0;;
	while(!pq[1].empty())	pq[1].pop();
	while(!pq[2].empty())	pq[2].pop();
	while(!pq[3].empty())	pq[3].pop();
	ans = 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		init();
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		
		for(int i=1;i<=n;i++)
		{
			pair<int,int> t = getmax(a[i]);
			if(!solve(t,i,0))
			{
				t = getminer(a[i],t.second);
				if(!solve(t,i,0))
				{
					t = getminer(a[i],t.second);
					solve(t,i,1);
				}
			}
		}
//		cout<<1<<endl;
//		while(!pq[1].empty())
//		{
//			cout<<pq[1].top().y<<' '<<pq[1].top().z<<endl;pq[1].pop();
//		}cout<<2<<endl;
//		while(!pq[2].empty())
//		{
//			cout<<pq[2].top().y<<' '<<pq[2].top().z<<endl;pq[2].pop();
//		}cout<<3<<endl;
//		while(!pq[3].empty())
//		{
//			cout<<pq[3].top().y<<' '<<pq[3].top().z<<endl;pq[3].pop();
//		}
		cout<<ans<<endl;
	}
	return 0;
}
