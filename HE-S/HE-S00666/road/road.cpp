#include <iostream>
#include <stdio.h>
#include <cstdio>  //prim algorithm is ok but without time
#include <algorithm>
#include <vector>
using namespace std;
#define rmax 2000000

int prim(int n,int e,vector<vector<int> > v){ // e=m+k*n
	int ui[rmax];int uil;
	sort(v.begin(),v.end(),[&](vector<int> e1,vector<int> e2){
		if (!binary_search(ui,ui+))
	});
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	// Ä¬ÈÏAi=0,deal with sp_case A 
	int n, m, k;
	cin>>n>>m>>k;
	vector<vector<int> > v(rmax,vector<int>(3));
	for (int i=0;i<m;i++){
		int uuu,vvv,www;
		scanf("%d %d %d",&uuu,&vvv,&www);
		vector[i][0]=uuu;vector[i][1]=vvv;vector[i][2]=www;
	}
	for (int i=0;i<k){
		int uselessvariable=0;cin>>uselessvariable;
		
	}
	return 0;
}
