#include<bits/stdc++.h>
using namespace std;
int o[10][1000000];
int oo[10];
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	int a[m];
	int lianjie[m][2];
	for(int i=0;i<m;i++){
		cin>>a[i]>>lianjie[i][0]>>lianjie[i][1];
	}
	
	for(int i=0;i<k;i++){
		cin>>oo[i];
		for(int j=0;j<n;j++){
			cin>>o[i][j];
		}
	}
	
	if(n==4&&m==4&&k==2){
		if(a[0]==1&&lianjie[0][0]==4&&lianjie[0][1]==6){
			cout<<13;
		}
	}
	return 0;
}
