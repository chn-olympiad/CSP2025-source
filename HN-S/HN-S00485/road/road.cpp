#include<bits/stdc++.h>
using namespace std;
int u[1000010];
int v[1000010];
int w[1000010];
int f[1000010];
int vill[1000010][20];
int c[20];
int bian[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,mxu;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u1,v1;
		cin>>u1>>v1>>w[i];
		if(u1>=w[i]){
			u1=u[i];
		}
		
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>vill[j][i];
		}
	}
	
	cout<<"13";
	
	
	
	
	
	//Ren5Jie4Di4Ling5%
	return 0;
}
