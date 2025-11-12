#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,cnt,sum,ans,a[N][3],vis[3],ok[N];
priority_queue<pair<int,pair<int,int> > >q;
void fun(int del)
{
	cnt=n;
	sum=vis[0]=vis[1]=vis[2]=0;
	for(int i=1;i<=n;i++) ok[i]=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i][del];
		if(del!=0) q.push({a[i][0]-a[i][del],{i,0}});
		if(del!=1) q.push({a[i][1]-a[i][del],{i,1}});
		if(del!=2) q.push({a[i][2]-a[i][del],{i,2}});
	}
	while(!q.empty())
	{
		auto w=q.top();
		q.pop();
		if(vis[w.second.second]==n/2||ok[w.second.first]) continue;
//		cout<<w.first<<" "<<w.second.first<<" "<<w.second.second<<endl;
		sum+=w.first;
		ok[w.second.first]=1;
		vis[w.second.second]++;
		cnt--;
		if(cnt<=n/2) ans=max(ans,sum);
	}
	return;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	ans=0;
	fun(0);
	fun(1);
	fun(2);
	cout<<ans<<"\n";
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
