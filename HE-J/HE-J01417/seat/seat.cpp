#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m]={},b[n*m];
	for(int i=0;i<n*m;i++) cin>>b[i];
	int s=b[0],x=0,y=0;
	sort(b,b+m*n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j==0) a[i][j]=i;
			else if(j==1) a[i][j]=2*n-1-a[i][0];
			else if(j>1) a[i][j]=a[i][j-2]+2*n;
		}
	}
	for(int i=0;i<n*m;i++){
		if(b[i]==s){
			s=n*m-i-1;
			break;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s==a[i][j]){
				cout<<j+1<<' '<<i+1; 
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

