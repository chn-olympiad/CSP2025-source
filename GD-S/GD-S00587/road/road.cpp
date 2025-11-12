#include <bits/stdc++.h>
using namespace std;
int mp[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,cost;
		cin>>x>>y>>cost;
		mp[x][y]=cost;
		mp[y][x]=cost;
	}
	int c;
	cin>>c;
	for(int i=1;i<=k;i++){
		int a;
		cin>>a;
	}
	return 0;
} 
