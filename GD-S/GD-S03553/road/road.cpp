#include<bits/stdc++.h>
using namespace std;
int n,m,k;

int main(){
	int city1,city2;
	freopen("road.in",r,stdin);
	freopen("road.out",w,stdout);
	cin>>n>>m>>k;
	int rd[n+k+1][n+k+1]={0};
	for(int i=1;i<=m;i++){
		cin>>city1>>city2;
		cin>>rd[city1][city2];
		rd[city2][city1]=rd[city1][city2];
	}
	for(int i=1;i<=j){
		
	}
	return 0;
}
