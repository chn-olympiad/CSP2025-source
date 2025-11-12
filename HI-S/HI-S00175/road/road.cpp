#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l[10011],vis[10011],flag[11];
vector<pair<int,int> > a[10011];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		a[x].push_back(make_pair(y,w));
		a[y].push_back(make_pair(x,w));
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=m;j++){
			int w;
			cin>>w;
			a[n+i].push_back(make_pair(j,w));
			a[j].push_back(make_pair(n+i,w));
		}
	}
	l[1]=1;
	vis[1]=1;
	for(int i=2;i<=n+k;i++) l[i]=1e18;
	for(auto i:a[1]) l[i.first]=i.second;
	for(int i=2;i<=n+k;i++){
		int x,y;
		for(int j=2;j<=n+k;j++){
			if(l[j]!=1e18&&vis[j]==0){
				x=l[j];
				y=j;
			}
		}
		if(y>n&&flag[y]==0)
		vis[y]=1;
		for(auto j:a[1]) l[j.first]=min(l[j.first],(long long)j.second+x);
		if(i==n){
			cout<<l[y];
		}
	}
	return 0;
}
/**/
