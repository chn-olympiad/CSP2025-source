#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,k;
vector<pair<int,int> > v[10010];
int c[20];
int a[20][10010];
priority_queue<pair<int,pair<int,int>> > q;
int f[10020];
int ans=-1000000000;
int F(int x){
	if(x==f[x]) return x;
	return f[x]=F(f[x]);
}
void dfs(int xxx){
	int sum=0,s=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			q.push({v[i][j].second,{i,v[i][j].first}});
		}
	}
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=0;i<k;i++){
		if((xxx&(1<<i))){
			sum-=c[i+1];s++;
			for(int j=1;j<=n;j++) q.push({0-a[i+1][j],{i+1+n,j}});
		}
	}
	int i=0;
//	cout<<sum<<"\n";
	while(q.size()&&i<n-1+s){
		int w=q.top().first,x=q.top().second.first,y=q.top().second.second;
		q.pop();
		int fx=F(x),fy=F(y);
		if(fx==fy) continue;
		i++;
		sum+=w;
		f[fx]=fy;
//		cout<<sum<<" "<<w<<" "<<x<<" "<<y<<"\n";
	}
	ans=max(ans,sum);
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int flag=1;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,-w});
		v[y].push_back({x,-w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=0;i<(1<<k);i++){
		dfs(i);
//		cout<<"\n";
	}
	cout<<-ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
