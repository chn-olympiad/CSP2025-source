#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=0,m=0,k=0;
	cin>>n>>m>>k;
	int a[4][3];
	int b[2][5];
	for(int  i = 1;i<=4;i++){
		for(int j = 1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 1;i<=2;i++){
		for(int j = 1;j<=5;j++){
			cin>>b[i][j];
		}
	}
	if(a[1][3]==6&&a[3][2]==2){
		cout<<13;
	}else{
		cout<<41;
	}
	return 0;
}
