#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long out=0,n,m,k,w,uv,uv1,a[10000][2];
	
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>uv>>uv1>>w;

		
		out+=w;
	}
	cout<<out;
	return 0;
}
