#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	int a[m][n];
	bool f=0;
	int c[m*n+1];
	int b=a[1][1];	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];	
		}
	}
	for(int t=1;t<=m*n;t++){
		if(m%2==0){
			int x=1;
			for(int i=1;i<=m/2;i++){
				for(int j=x;j<=x+n-1;j++){
					c[t]=a[i][j];
				}
				for(int j=x+n;j<=x+2*n-1;j++){
					c[t]=a[i+1][j];
				}
				x+=2*n;		
			}
		}
		else{
			int x=1;
			for(int i=1;i<=(m-1)/2;i++){
				for(int j=x;j<=x+n-1;j++){
					c[t]=a[i][j];
				}
				for(int j=x+n;j<=x+2*n-1;j++){
					c[t]=a[i+1][j];
				}
				x+=2*n;		
			}
			for(int i=m;i<=m;i++){
				for(int j=x;j<=x+n-1;j++){
					c[t]=a[i][j];
				}
			}
		}
	}
	
	sort(c+0,c+m*n);
	for(int i=1;i<=m*n;i++){
		if(c[i]==b){
			cout<<i/n<<i/m;
		}
	}
	return 0;
}
