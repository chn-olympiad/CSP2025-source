#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1001000],v[1001000],w[1001000],sss,s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k*(n+1);i++){
		cin>>sss;
	}
	sort(w,w+m);
	for(int i=0;i<m-k;i++){
		s+=w[i];
	}
	cout<<s;
	return 0;
}

