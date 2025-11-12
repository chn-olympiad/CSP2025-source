#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	//n为城市数量 m为道路数量 k为乡村数量 
	cin>>n>>m>>k;
	int count=m+k*n;
	int cityfy[n];
	long long roads[count][4];
	for(int i=0;i<m;i++){ //城市1 城市2 两城道路费用 
		cin>>roads[i][0]>>roads[i][1]>>roads[i][2];
		cityfy[i]=roads[i][2];
		roads[i][3]=0; //城市没有改造费用 
	}
	long long xzhen[k][n+1];
	for(int i=0;i<k;i++){ //改造费用 后面j个为通向城市费用 
		cin>>xzhen[i][0];
		for(int j=0;j<k;j++){
			cin>>xzhen[i][j+1];
		}
	}
	int x=m+1;
	//int xcfy
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			roads[x][0]=m+i; //第几个乡村 
			roads[x][1]=j+1; //第几个城市
			roads[x][2]=xzhen[i][j+1]; //两地间成本
			roads[x][3]=xzhen[i][0]; //乡村改造费用 
		}
	}
	int used[k]={0};
	//全都不会写 
	
	return 0;
}
