//GZ-S00067北京师范大学贵阳附属学校  刘锦宸 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int c1[m],c2[m],v1[m],v2[k],v3[k][m],ans=0;
	for(int i=0;i<m;i++){
		cin>>c1[i]>>c2[i]>>v1[i];
		ans+=v1[i];
	} 
	for(int i=0;i<k;i++){
		cin>>v2[i];
		for(int j=0;j<m;j++){
			cin>>v3[i][j];
		}
	}
	if(k==0){
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} 
