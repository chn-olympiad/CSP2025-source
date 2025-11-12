#include<bits/stdc++.h>
using namespace std;
int mark[235],seat[15][15];
int n,m;
int main(){
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>mark[i];
	}
	int r=mark[1];
	while(1){
		int f=1;
		for(int i=1;i<=num-1;i++){
			if(mark[i]<mark[i+1]){
				swap(mark[i],mark[i+1]);
				f=0;
			}
		}
		if(f) break;
	}
	int j=1,k=1;
	for(int i=1;i<=num;i++){
		seat[j][k]=mark[i];
		if(j%2==1){
			if(k==m) j++;
			else k++;
		}
		else{
			if(k==1) j++;
			else k--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==r) cout<<i<<" "<<j;
		}
	}
	return 0;
} 
