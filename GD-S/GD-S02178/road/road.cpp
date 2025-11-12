#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=1e6+5;
vector<int> e[N];
pair<int,int> Path[M];
int v[M],st[N];
int a[M],b[15],c[15];
int n,m,k,ma=(1<<30);
void Run(int x){
	st[x]=1;
	for(auto t:e[x]){
		if(!st[t])Run(t);
	}
	return;
}
int link(int tot){
	for(int i=1;i<=n;i++)b[i]=0;
	for(int i=1;i<=n;i++)e[i].clear();
	int sum=0;
	for(int i=1;i<tot;i++){
		int x=Path[a[i]].first,y=Path[a[i]].second;
		e[x].push_back(y);
		e[y].push_back(x);
		sum+=v[a[i]];
		if(x>n)b[x-n]=1;
		if(y>n)b[y-n]=1;
	}
	for(int i=1;i<=k;i++)
		if(b[i])sum+=c[i];
	return sum;
}
void solve(int idx,int last){
	if(last>m){
		int ans=link(idx-1);
		for(int i=1;i<=n;i++)st[i]=0;
		Run(1);
		for(int i=1;i<=n;i++)
			if(!st[i])return;
		ma=min(ma,ans);
		return;
	}
	for(int i=last+1;i<=m+1;i++){
		a[idx]=i;
		solve(idx+1,i);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y>>v[i];
		Path[i]={x,y};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>v[m+i*j];
			Path[m+i*j]={n+i,j};
		}
	}
	m+=k*n;
	solve(1,0);
	cout<<ma;
}
