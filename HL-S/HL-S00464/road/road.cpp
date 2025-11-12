#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000000];
int b[1000000];
int c[1000000];
int ty=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
		ty+=c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	cout<<ty;
	
	
	return 0;
}