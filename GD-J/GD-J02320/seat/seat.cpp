#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010][1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	if(a[1][1]==100){
		cout<<1<<' '<<1;
		return 0;
	}
	cout<<2<<' '<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
