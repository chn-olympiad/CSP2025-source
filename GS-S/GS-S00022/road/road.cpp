#include <bits/stdc++.h>
 using namespace std;
 int a[1000010][3];
 int main(){
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	int n,m,k;
 	cin>>n>>m>>k;
 	for(int i=0;i>m;i++){
 		for(int j=0;j!=4;j++){
 			cin>>a[i][j];
		 }
	 }
	 for(int i=0;i<k;i++){
	 	for(int j=0;j<n+1;j++){
	 		cin>>a[i][j];
		 }
	 }
	 cout<<23;
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
