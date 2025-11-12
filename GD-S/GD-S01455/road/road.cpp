#include<bits/stdc++.h>
using namespace std;
long n,m,k,u,v,w,c,a,s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		cin>>u>>v>>w;
		s+=w;
	}
	while(k--){
		cin>>c;
		for(int i=0;i<n;i++)cin>>a;
	}
	cout<<s;
}
