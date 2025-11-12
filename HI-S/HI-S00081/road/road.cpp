#include<bits/stdc++.h>
using namespace std;
int n,m,k,jg;
long long a[10004][10005];
int b[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int v1,v2,w;
		cin>>v1>>v2>>w;
		a[v1][v2]=w;
		jg+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
	}
	cout<<jg;
	return 0;
}
