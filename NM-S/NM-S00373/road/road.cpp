#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int cnt=0;
	int a[100006][100006];
	for(int i=1;i<=m;i++){
		int x,y,p;
		cin>>x>>y>>p;
		a[x][y]=a[y][x]=p;
		cnt+=p;
	}
	cout<<cnt;
	return 0;
}
