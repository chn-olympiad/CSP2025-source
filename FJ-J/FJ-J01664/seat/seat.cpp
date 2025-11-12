#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m,ans;
	cin>>n>>m;
	int a[100][100],b[n*m+5]={};
	for(int i=1;i<=m*n;i++){
		cin>>b[i];
		if(i==1){
			ans=b[i];
		}
	}
	sort(b,b+m*n+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2!=0){
				a[i][j]=b[m*n-(i*n+j-n-1)];
				
			}
			else
			{
				a[i][j]=b[m*n-(i*n-j)];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(ans==a[i][j]){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
} 


 
