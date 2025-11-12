#include <bits/stdc++.h>
using namespace std; 
int a[105];
int c[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q=1,x=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				c[i][j]=a[q];
				q++;
			}
		}else{
			for(int i=n;i>=1;i--){
				c[i][j]=a[q];
				q++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==x){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
