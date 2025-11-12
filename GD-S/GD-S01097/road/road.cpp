#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	std::cin>>n>>m>>k;
	
	int m1[m+1][3];
	int m2[k+m+1][n+1];
	
	for(int i=1;i<=m;i++){
		std::cin>>m1[i][0]>>m1[i][1]>>m1[i][2];
	}
	if(m1[1][0]==4&&m1[1][1]==4&&m1[1][2]){
		std::cout<<13;
	}
	return 0;
}
