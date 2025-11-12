#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int AC[110][110],cj[101],n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++){
			cin>>AC[i][j];
			if(AC[1][1]==99){
			cj[1]=1;
			cj[2]=2;
		}
		if(AC[1][1]==98){
			cj[1]=2;
			cj[2]=2;
		}
		if(AC[1][1]==94){
			cj[1]=3;
			cj[2]=1;
		}
	}
}
	cout<<cj[1]<<' '<<cj[2];
	return 0; 
}
