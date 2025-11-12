#include<bits/stdc++.h>
using namespace std;
int n,m,p=1,x=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a1[(n+1)*(m+1)],a[n+1][m+1];
	cin>>a1[1];
	for(int i=2;i<=n*m;i++){
		cin>>a1[i];
		if(a1[i]>a1[1]){
			x++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){ 
			for(int j=1;j<=n;j++){
				a[j][i]=p;
				p++;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=p;
				p++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==x){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
