#include<bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(ll i=(a);i<=(b);i++)
using namespace std;
const ll N=1e4+10;
ll n,m,x,w,y,k;
struct node{
	ll v,w;
};
vector<node> a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	fo(i,1,m){
		cin>>x>>y>>w;
		a[x].push_back({y,w});
		a[y].push_back({x,w});
	}
	fo(i,1,k){
		fo(j,1,n+1)cin>>x;
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
