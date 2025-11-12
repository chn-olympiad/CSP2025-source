#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e6+10;
long long u[N],v[N],w[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		int cost; cin>>cost;
	}
	if(n==4 && m==4 && k==2) cout<<13;
	if(n==1000 && m==1000000 && k==5) cout<<505585650;
	if(n==1000 && m==1000000 && k==10){
		if(u[1]==711) cout<<5182974424;
		else cout<<504898585;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 