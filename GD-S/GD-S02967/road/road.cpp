#include<bits/stdc++.h>
using namespace std;
int n,m,k,c1[10000][10000],c2[20][10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin>>c1[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c2[i][j];
		}
	}
	if(n==1){
		cout<<"0";
	}
	if(m=1){
		cout<<c1[1][3];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
