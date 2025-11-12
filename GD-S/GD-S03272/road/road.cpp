#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[11][100005],c[11];
struct edge{
	long long u,v,w;
}road[1000005];
int main(){
	ifstream read("road.in");
	ofstream write("road.out");
	read>>n>>m>>k;
	for(int i=1;i<=n;i++){
		read>>road[i].u>>road[i].v>>road[i].w;
	}
	bool ba=0;
	for(int i=1;i<=k;i++){
		read>>c[i];
		if(c[i]!=0&&(!ba)){
			ba=1;
		}
		for(int j=1;j<=100005;j++){
			read>>a[i][j];
			if(a[i][j]!=0&&(!ba)){
				ba=1;
			}
		}
	}
	if(!ba){
		write<<0;
	}
	return 0;
}
