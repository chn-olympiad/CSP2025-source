#include<bits/stdc++.h> 
using namespace std;
int re[2][10001]={0};
struct r{
	int b;
	int e;
	int w;
}r[10000];
struct c{
	int w;
	int ww[10001]={0};
}c[11];
int main(){
	define("road.in");
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>r[i].b>>r[i].e>>r[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>c[i].w;
		for(int j=0;j<n;i++){
			cin>>c[i].ww[j];
		}
	}
	queue<int> a;
	a.push(1);
	for(int i=2;i<=n;i++){
		re[1][i]=99999;
	}
	for(int i=0;i<m;i++){
		if(r[i].e==1&&r[i].w<re[1][1]){
			re[1][1]=r[i].w;
			re[0][1]=r[i].b;
		}
	} 
	while(!a.empty()){
		int b=a.front();
		a.pop();
		for(int i=0;i<m;i++){
			if(r[i].b==b){
				if(re[1][r[i].e]>r[i].w+re[1][re[0][r[i].e]]){
					a.push(r[i].e);
					re[1][r[i].e]=r[i].w+re[1][re[0][r[i].e]];
					re[0][r[i].e]=b;
				}
			}
		}
	}
	int ma=0;
	for(int i=1;i<=n;i++){
		ma+=re[1][i];
	}
	cout<<ma;
	define("road.out");
	return 0;
}
