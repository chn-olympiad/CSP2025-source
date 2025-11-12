#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000][1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;

	}	

}
