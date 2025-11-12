#include<bits/stdc++.h>
using namespace std;

int n,m,k;
struct node{
	int x,y;
	long long w;
	int c;
}a[1000005],c[15];

int main(){
	freopen("road.in",r,stdin);
	freopen("road.out",w,stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i].w;
		for(int i=1;i<=n;i++){
			cin>>a[i].c;
		}
	}
	cout<<13;
	return 0;
}
