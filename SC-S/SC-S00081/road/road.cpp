#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,z,dis[10005],ans;
queue<int>q;
struct node{
	long long u,v,w;
};
node b;
vector<node> v; 
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		ans+=z;
		b.u=x,b.v=y,b.w=z;
		v.push_back(b);
	}
	cout<<ans;
	return 0;
} 