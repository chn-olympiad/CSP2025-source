#include<bits/stdc++.h>

#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 1e5 + 10;
int n,ans;
struct node{
	int a;
	int b;
	int c;
	int change;
}date[N];
priority_queue<int> pq[3];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--)
	{
		cin>>n;ans = 0;
		for(int ix=0;ix<=3;ix++) while(pq[ix].size()) pq[ix].pop();
		for(int i=1;i<=n;i++)
		{
			cin>>date[i].a>>date[i].b>>date[i].c;
			int Max = max({date[i].a,date[i].b,date[i].c});
			int twice;
			if(Max == date[i].a) twice = max(date[i].b,date[i].c);
			else if(Max == date[i].b) twice = max(date[i].a,date[i].c);
			else twice = max(date[i].b,date[i].a);
			date[i].change = Max - twice;
			if(Max == date[i].a) pq[0].push(-date[i].change);
			else if(Max == date[i].b) pq[1].push(-date[i].change);
			else pq[2].push(-date[i].change);
			ans += Max;
		}
		int dix;
		if(pq[0].size() > n/2) dix = 0;
		else if(pq[1].size() > n/2) dix = 1;
		else dix = 2;
		while(pq[dix].size() > n/2)
		{
			ans += pq[dix].top();
			pq[dix].pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}