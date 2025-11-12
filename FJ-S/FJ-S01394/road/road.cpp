#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,s=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		s+=w;
	}
	for(int i=1;i<=n+1;i++){
		cin>>w;
		if(i!=1){
			s+=w;
		}
	}
	cout<<s; 
	return 0;
} 
