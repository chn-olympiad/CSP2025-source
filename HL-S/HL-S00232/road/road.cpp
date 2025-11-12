#include <bits/stdc++.h>
using namespace std;
int arrm[1000010][4];

 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>arrm[i][1];
		cin>>arrm[i][2];
		cin>>arrm[i][3];
	}
	
	int sum=0;
	for(int i=1;i<=m;i++){
		sum+=arrm[i][3];
	}
	cout<<sum;
	
	
	return 0;
} 
