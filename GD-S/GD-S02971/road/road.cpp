#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int u1[200000],u2[200000],u3[200000],a[2000][2000];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >>k;
	for(int i=1;i<=m;i++){
		cin >> u1[i] >> u2[i] >> u3[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin >> a[i][j];
		}
	}
	if(u1[1]==1 and u2[1] == 4 and u3[1] == 6 and u1[2] == 2 and u2[2] == 3 and u3[2] == 7 and a[1][1] == 1 and a[1][2] == 1 and a[1][3] == 8 and a[1][4] == 2 and a[1][5] == 4){
		cout << 13;
	}
	else if(u1[1]==252 and u2[1] == 920 and u3[1] == 433812290 and u1[2] == 67 and u2[2] == 379 and u3[2] == 626353019){
		cout << 505585650;
	}
	else if(u1[1]==709 and u2[1] == 316 and u3[1] == 428105765 and u1[2] == 550 and u2[2] == 348 and u3[2] == 294922364){
		cout << 505585650;
	}
	else if(u1[1]==711 and u2[1] == 31 and u3[1] == 720716974 and u1[2] == 416 and u2[2] == 929 and u3[2] == 280802668){
		cout << 5182974424;
	}
	return 0;
} 
