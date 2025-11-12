#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.seat","r",stdin);
	freopen("output.seat","w",stdout);
	int n,m,a[100][100],x=1,z=1,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>a[1][1])x++;
		}
	}while(x>n){
		x-=n;
		z++;
	}if(z%2==1)y=x;
	if(z%2==0)y=n-x+1;
	cout<<z<<" "<<y;
	return 0;
}
