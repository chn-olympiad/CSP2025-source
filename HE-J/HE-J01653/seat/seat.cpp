#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,f;
	int fen[1010]={},ma[1010][1010]={};
	cin>>n>>m;
	
	
	for(int i=1;i<=n*m;i++){
		cin>>fen[i];
	}
	f=fen[1];
	if(m>0&&n>0){
		ma[1][1]=1;
	}
	sort(fen+1,fen+n*m+1);
	for(int i=1;i<=m*n;i++){
		if(fen[i]==t){
			f=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ma[i][j+2]=j+n*2;
			if(ma[i][j]==f){
				cout<<i<<j;
			}
		}
	}
	
	
	return 0;
} 
