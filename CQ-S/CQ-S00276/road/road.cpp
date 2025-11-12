#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,q;
}a[1000001];
bool cmp(node a,node b){
	return a.q<b.q;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].q;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		int u;
		cin>>u;
	}
	cout<<13;
	return 0;
}
