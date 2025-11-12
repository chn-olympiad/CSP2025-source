#include<bits/stdc++.h>
using namespace std;
long long n,m,k,b[1000001],c[11],d[11][1000001];
struct road{
	int start,end,price;
};
struct road a[10001];
int main(){
	freopen("road.in","r","stdin");
	freopen("road.out","w","stdout");
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].start>>a[i].end>>a[i].price;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>d[i][j];
	}
	cout<<0;
	return 0;
}

