#include<bits/stdc++.h> 
using namespace std;
int main(){
int m,n,a[100],a1,b[100][100],k; 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	cin>>a[0];
	a1=a[0];
	for(int i=1;i<m*n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m*n;i++){
		for(int j=0;j<m*n;j++){
			if(a[j+1]<a[j]){
				swap(a[j+1],a[j]);
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			b[i][j]=a[k];
			k++;
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a1==b[i][j]){
				cout<<i<<' '<<j+1;
			}
		}
	}
return 0;
}
