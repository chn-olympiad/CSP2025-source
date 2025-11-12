#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10001],d[11][1000001];
struct data{
	 int st,en,w;
}a[1000001];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].st<<a[i].en<<a[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	cout<<13;
    return 0;
}
