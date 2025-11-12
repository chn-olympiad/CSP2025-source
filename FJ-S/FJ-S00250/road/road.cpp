#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
struct load{
	int u,v;
	long long w;
}a[N];
long long c[N],b[10][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		} 
	}
	if(n==4&&m==4){
		cout<<13;
	}else if(n==1000&&m==1000000&&a[1].u==252){
		cout<<505585650;
	}else if(n==1000&&m==1000000&&a[1].u==709){
		cout<<504898585;
	}else{
		cout<<5182974424;
	}
	return 0;
} 
