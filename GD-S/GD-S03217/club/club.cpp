#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,mod=1e9+7;
struct node
{
	int x,id;
}a[10];
bool cmp(node x,node y)
{
	return x.x>y.x; 
}
void solve()
{
	priority_queue<int,vector<int>,greater<int>>pq[5];
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[1].x>>a[2].x>>a[3].x;
		a[1].id=1,a[2].id=2,a[3].id=3;
		sort(a+1,a+4,cmp);
		ans+=a[1].x;
		pq[a[1].id].push(a[1].x-a[2].x);
	}
	for(int i=1;i<=3;i++) while((int)(pq[i].size())>n/2) ans-=pq[i].top(),pq[i].pop();
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve(); 
	return 0;
}
/*
WARNING: All my comments after the code are in UTF-8 format. Do not use Dev-C++ to view.
大家好，我是去年的 GD-S03043，今年回来啦！
我要蓝钩！！！
题外话：关注 @Shellchen 谢谢喵！
---------------------------------------不怎么优雅的分割线---------------------------------------
100pts
*/
