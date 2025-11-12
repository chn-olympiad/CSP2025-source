#include<bits/stdc++.h>
using namespace std;
bool cpp(int a,int b){
	if(a>b){
		return 1;
	}
	if(a<b){
		return 0;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[105]={0};
	
	int grid[n+5][m+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int ming=a[1];
	sort(a+1,a+(n*m)+1,cpp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==0){
				grid[i][j]=a[i*m-j+1];
				
			}
			else{
				grid[i][j]=a[(i-1)*m+j];
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(grid[i][j]==ming){
				cout<<i<<' '<<j;
			}
		}
	}
	
	return 0;
} 
