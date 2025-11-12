#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[10][10];
	int c[101];
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int y=c[1];
	sort(c+1,c+n*m+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
			a[i][j]=c[b];
			b--;		
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==y){
				cout<<i<<" "<<j;
			}
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
