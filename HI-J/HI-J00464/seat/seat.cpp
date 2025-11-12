#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	int a[s]={0},b[1]={0};
	//const 
	int c[n][m];
	for(int i=0;i<s;i++){
		cin>>a[i];
		b[i]=a[0];
	} 
	sort(a,a+s,cmp);
	/*for(int i=0;i<s;i++){
		cout<<a[i]<<" ";		
	} */
	int t=n;
	if(n%2==0){
		for(int z=1;z<n;z=z+1){			
			
			for(int i=1;i<=m;i++){
				c[z][i]=a[i];
			}
			
			for(int j=n;j>=1;j--,t++){
					t=t-1;
					c[z+1][j]=a[t];					
			}				
											
		}	
	}
	else{
		for(int z=1;z<=m;z=z+2){
			int t=n+1;
			for(int i=1;i<=n;i++){
				c[z][i]=a[i];
			}
			if(m%2==0){
				for(int j=n;j>=1;j--,t++){
					t=t+1;
					c[z+1][j]=a[t];
				}				
			}								
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]=b[1]){
				cout<<i<<" "<<j;
				return 0;
			}
			 
		}
	} 
		
	
		
		
	
	
	
	return 0;
}
