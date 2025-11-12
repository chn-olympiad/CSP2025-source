#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	if(n<=1&&m<=1){
//		cin>>a[1][1];
		cout<<n<<' '<<m;
	}
	return 0;
} 
