#include<bits/stdc++.h>
using namespace std;
int main(){
 	freopen("road.in","r",stdin);
 	freopen("road.out","W",stdout);
 	int n,m,k;
 	cin>>n>>m>>k;
 	int x[m*3];
 	int y[k*5];
 	int x1[m];
 	int ans=0;
 	
 	for (int i;i<=m*3;i++){
 		cin>>x[i];
	 }
 	for (int i;i<=k*5;i++){
 		cin>>y[i];
	 }
	for (int i;i<=m;i++){
		if(i%2==2){
			x1[i]=x[i];
		}
	 }
	for (int i;i<=m/2;i++){
 		ans+=x1[i];
	 }
	 cout<<ans;
 	
	return 0;
}
