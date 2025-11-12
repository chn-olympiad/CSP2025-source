
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[m*n];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=i;j<n*m;j++){
			if(a[i]<a[j]){ 
				int c;
				c=a[i];
				a[i]=a[j];
				a[j]=c; 
			}
		}
	}
	int b[m][n];
	int num=0;
	for(int i=0;i<m;i++){
		if((i+1)%2==0){
			for(int j=n;j>0;j--){
				b[i][j]=a[num];
				num++;
			}
		}else{
			for(int j=0;j<m;j++){
				b[i][j]=a[num];
				num++;
			}
		}
	}
	int t=0;
	for(int i=0;i<m;i++){
		if((i+1)%2==0){
			for(int j=n;j>0;j--){
				if(b[i][j]==r){
					cout<<i+1<<" "<<j;
					t=1;
					break;
				}
			}	
		}else{
			if(t!=0){
				break;
			} 
			for(int j=0;j<n;j++){
				if(b[i][j]==r){
					cout<<i+1<<" "<<j+1;
					break;
				}
			}	
		}
		
		
	}
	return 0;
}
