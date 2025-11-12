#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;	
	}
	for(int i=0;i<k;i++){
		int a,b,u,v,k;
		cin>>a>>b>>u>>v>>k;
		sum+=k;
	}
	cout<<sum;
	return 0;
}
