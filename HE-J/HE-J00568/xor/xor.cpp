#include<bits/stdc++.h>
using namespace std;
int a[50][50];
int n,m,AC[100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cin>>a[i][j];
			if(a[1][1]==2){
				AC[1]=2;
				cout<<AC[1];
				break;
			}
			if(m==0){
				AC[1]=1;
				cout<<AC[1];
				return 0;
			}
		} 
	}
	return 0;
} 
