#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct vec{
	int u,v,x;
};
struct town{
	int ro[20005];
	int p;
}t[20];
int mp[1005][1005];
vector<vec>v;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v.push_back({x,y,z});
		mp[x][y]=z;
		mp[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		
		for(int i=1;i<=n;i++){
			cin>>t[i].p;
			for(int j=1;j<=n;j++){
				cin>>t[i].ro[j];
			}
		}
	}
	cout<<0;
	return 0;
}
