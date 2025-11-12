#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum;
	return 0;
}
