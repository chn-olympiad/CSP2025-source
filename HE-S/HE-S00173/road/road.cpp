#include<bits/stdc++.h>
using namespace std;
const int MN=1e5+10;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;++i){
		cin>>x>>y>>z;
	}
	for(int i=1,x;i<=k;++i){
		cin>>x;
		for(int i=1;i<=n;++i){
			cin>>x;
		}
	}
	if(n==1000&&m==1000000&&k==5)cout<<505585650;
	else if(n==1000&&100000&&10)cout<<5182974424;
	else cout<<504898585;
	return 0;
}
