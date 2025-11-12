#include <bits/stdc++.h>

using namespace std;
struct road{
	int s;
	int e;
	long long w;
}r[1100000];
struct town{
	int ec;
	long long money;
}t[1100000];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >>n>>m>>k;
	for(int i=0;i<m;i++){
		cin >>r[i].s;
		cin >>r[i].e;
		cin >>r[i].w;
	}
	for(int i=0;i<k;i++){
		for(int j=1;j<=m;j++){
			t[i].ec=m;
			cin >>t[i].money;
		}
	}
	for(int i=0;i<m;i++){
		ans+=r[i].w;
	}
	cout <<ans;
	return 0;
}