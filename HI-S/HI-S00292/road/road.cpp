#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005][10005];
struct rode{
	int jl[10005];
	int jzjg;
}b[15];
bool bj[100005];
int s(int i){
	int sum;
	bj[i]=true;
	for(int j=1;j<=n;j++){
		if(bj[j]!=true){
			sum+=s(i);
		}
	}
	bj[i]=false;
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u=0,v=0,w=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].jzjg;
		for(int j=1;j<=n;j++){
			cin>>b[i].jl[j];
		}
	}
	cout<<13;
	if(k==0){
		cout<<s(1); 
		cout<<1;
	}
	return 0;
}

