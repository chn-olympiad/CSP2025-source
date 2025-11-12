#include<bits/stdc++.h>
using namespace std;
constexpr int N=10005;

int a[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int sum=0;
	while(m--){
		int u,v,w; cin>>u>>v>>w;
		sum+=w;
	}
	while(k--){
		int c; cin>>c;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	cout<<sum<<"\n";
	return 0;
}
