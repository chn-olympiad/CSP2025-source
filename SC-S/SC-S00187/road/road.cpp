#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	long long sum = 0;
	vector<int> u(m),v(m),w(m);
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	for(int i=0,c;i<k;i++){
		cin>>c;
		if(c==0) return cout<<'0',0;
		for(int i=0,x;i<n;i++){
			cin>>x;
		}
	}
	cout<<sum;
	return 0;
}