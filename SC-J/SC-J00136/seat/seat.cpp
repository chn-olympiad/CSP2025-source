#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	int s[n][m]={0},temp[n*m];
	for(int i=0;i<n*m;i++){
		cin>>temp[i];
	}
	k=temp[0];
	sort(temp,temp+n*m);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i%2==0){
				s[i][j]=temp[j*n+i];
			}
			else{
				s[i][n-1-j]=temp[j*n+i];
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(k==s[i][j]){
				cout<<i+1<<" "<<j+1;
				return 0;
			}
		}
	}
}