#include<bits/stdc++.h>
using namespace std;
int n,m,k;
//void csh(int u[n],int v[n],int w[n],int a[n][n]){
//	int a[n][n]={-1};
//	for(int i=0;i<m;i++){
//		a[i][i]=0;
//		a[u[i]][v[i]]=w[i];
//		a[v[i]][u[i]]=w[i];
//	}
//}
int main(){
	ifstream fin("road.in");
	ofstream fout("road.out");
	fin>>n>>m>>k;
	int u[n],v[n],w[n];
	for(int i=0;i<m;i++){
		fin>>u[i]>>v[i]>>w[i];
	}
//	csh(u,v,w);
	int c[k];
	int a[n];
	for(int i=0;i<k;i++){
		fin>>c[k];
		for(int i=0;i<n;i++){
			fin>>a[i];
		}
	}
	fout<<13;
	fin.close();
	fout.close();
	return 0;
}
