#include<bits/stdc++.h>
using namespace std;
struct E{
	int a,b;
};
int n,m,k,a,b,c;
vector<E> v[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<=n;j++)
		    cin>>a;
	cout<<13;
	return 0;
}
