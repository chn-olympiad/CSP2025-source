#include<bits/stdc++.h>
using namespace std;
int abc(){
	int n;
	cin>>n;
	int a[n+1][3]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	int b=0;
	for(int i=0;i<n;i++){
		b+=max(a[i][0],max(a[i][1],a[i][2]));
	}
	return b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		cout<<abc()<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
