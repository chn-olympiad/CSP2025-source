#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,x,y;
int d[109];
int p[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n*m;i++){
		cin>>d[i];
		if(i==1){
			k=d[i];
		}
	}
	sort(d+1,d+1+n*m);
	for(int i=0;i<m;i++){
	
					for(int j=0;j<n;j++){
					if(i%2==0){
					p[i][m-j]=d[i*m-j];
					if(p[i][m-j]==k){
						cout<<i+1<<" "<<m-j;
						}	}
			p[i][j]=d[i*n+j];
			if(p[i][j]==k){
			cout<<i+1<<" "<<j+1;
		}
					
				
				}
			
	
		}
		
				return 0;
		}
		
			
	
	

