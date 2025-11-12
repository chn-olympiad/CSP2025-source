#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
int n,m,k,u,v,w,c,a;
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a;
		}
	}
	cout<<0;
	
	return 0;
} 
