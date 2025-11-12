#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,isum,t;
int sj[1000001];
signed  main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>t;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>sj[i];
	}
	sort(sj+1,sj+1+m);
	for(int i=1;i<=n-1;i++){
		isum+=sj[i];
	}
	cout<<isum;
	return 0;
}