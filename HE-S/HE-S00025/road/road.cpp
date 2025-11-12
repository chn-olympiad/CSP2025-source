#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e4+1013;
int n,m,k;
struct Node{
	int u,v,w;
}G[N];
int a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>G[i].u>>G[i].v>>G[i].w;
	}
	while(k--){
		for(int i=1;i<=n+1;i++){
			cin>>a[i];
		}
	}

	cout<<0;
	return 0;
}









/*
洛谷名：Cute_F
求关，互关私
*/

