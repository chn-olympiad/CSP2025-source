#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int m,n,k;
struct Edge{
	int u,v,w;
}e[N];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		ans+=c;
	}
	cout<<ans;
	return 0;
}
