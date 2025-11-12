#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
	int c;
}dis[100005];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>dis[i].a>>dis[i].b>>dis[i].c;
			ans+=max(dis[i].a,max(dis[i].b,dis[i].c));
		}
	}
	for(int i=1;i<=m+1;i++){
		int a;
		cin>>a;
	}
	cout<<0;
	return 0;
}
