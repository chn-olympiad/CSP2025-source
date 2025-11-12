#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,m,k,u[maxn],v[maxn],w[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;++i){
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	cout<<sum;
	return 0;
}

