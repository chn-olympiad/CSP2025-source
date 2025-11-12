#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct node
{
	pair<int,int> val[5];
	int opt;
}a[N];
struct cmp
{
	bool operator()(pair<int,int> &x,pair<int,int> &y)
	{
		return x.first>y.first;
	}
};
int T,n,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	int i,j,k,id;
	while(T--)
	{
		priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> q[4];
		ans=0;
		cin >> n;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].val[1].first,&a[i].val[2].first,&a[i].val[3].first);
			a[i].val[1].second=1;
			a[i].val[2].second=2;
			a[i].val[3].second=3;
			//ÅÅÐò 
			if(a[i].val[1].first<a[i].val[2].first) swap(a[i].val[1],a[i].val[2]);
			if(a[i].val[2].first<a[i].val[3].first) swap(a[i].val[2],a[i].val[3]);
			if(a[i].val[1].first<a[i].val[2].first) swap(a[i].val[1],a[i].val[2]);
			for(j=1;j<=3;j++)
			{
				if(q[a[i].val[j].second].empty()||q[a[i].val[j].second].size()<n/2)
				{
					ans+=a[i].val[j].first;
					q[a[i].val[j].second].push({a[i].val[j].first-a[i].val[j+1].first,i});
					a[i].opt=j;
					break;
				}
				else if(q[a[i].val[j].second].top().first<a[i].val[j].first-a[i].val[j+1].first)
				{
					id=q[a[i].val[j].second].top().second;
					if(a[id].opt==3) continue;
					ans-=q[a[i].val[j].second].top().first;
					q[a[i].val[j].second].pop();
					ans+=a[i].val[j].first;
					a[i].opt=j;
					q[a[i].val[j].second].push({a[i].val[j].first-a[i].val[j+1].first,i});
					a[id].opt++;
					q[a[id].val[a[id].opt].second].push({a[id].val[a[id].opt].first-a[id].val[a[id].opt+1].first,id});
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
