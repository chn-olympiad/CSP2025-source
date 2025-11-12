#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int u[N],v[N],w[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long int all=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		all+=w[i];
	}
	cout<<all;
	return 0;
}