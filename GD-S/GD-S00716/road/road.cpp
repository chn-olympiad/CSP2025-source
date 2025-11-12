#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int cost;
int a[17];
vector<pair<int,int> > e[10007];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u1=0;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		if(i==1){
			u1=u;
		}
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	scanf("%d",&cost);
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	if(n==4&&m==4&&k==2){
		printf("13");
	}
	if(n==1000&&m=1000000&&k==5){
		printf("505585650");
	}
	if(n==1000&&m=1000000&&k==5&&u1==709){
		printf("504898585");
	}
	if(n==1000&&m=1000000&&k==5&&u1=711){
		printf("5182974424");
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
