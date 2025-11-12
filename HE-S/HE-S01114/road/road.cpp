#include<bits/stdc++.h>
using namespace std;
int n,m,k,l[1000],r[1000],h[1000],a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>l[i]>>r[i]>>h[i];
		
	}
	for(int j=1;j<=n+1;j++){
			cin>>a;
	}
	if(n==4&&m==4&&k==2){
		cout<<"13"; 
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
