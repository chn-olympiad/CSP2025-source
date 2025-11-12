#include <bits/stdc++.h> std;
using namespace std;
int a[15][15];
int b[110];
int x;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];		
		if(i==0){
			x=b[i];
		}
	}
	
	
	sort(b,b+m*n);
	
	int p=1;
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==0){
				a[i][n-j+1]=b[m*n-p];
			}else{
			a[i][j]=b[m*n-p];
			}
			p=p+1;				
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==x){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
