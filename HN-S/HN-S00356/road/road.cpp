#include<bits/stdc++.h>
using namespace std;
int a[10000][10000],min;
int a1[10000][10000];
queue <int>q1;
void dfs(int p){
	if(p=m+k)return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,x,y,z;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>x>>y>>z;
			a[x][y]=1;
			a[x][z]=1;
		}
	}
	for(int j=0;j<k;j++){
		for(int i=0;i<n;i++){
			cin>>a[j][i];
		}
	}
	dfs(1);
}
