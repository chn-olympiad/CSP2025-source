#include<bits/stdc++.h>
using namespace std;
int n,m,k,d=0;
int a[10010],b[1000010],c[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		d+=c[i];
	}
	cout<<d;
	return 0;
}
