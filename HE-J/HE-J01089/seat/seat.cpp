#include<bits/stdc++.h>
using namespace std;
long long y[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>y[i][j];
			r=y[1][1];
			a=1,b=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r<y[i][j]){
				swap(y[1][1],y[i+1][j]);
				a=i,b=j;
				r=y[i+1][j];
			}
		}
	}cout<<a<<" "<<b;
	return 0;
} 
