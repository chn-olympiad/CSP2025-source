#include<bits/stdc++.h>
using namespace std;
long long n,a[5050],nxt=0,b[5050][5050][5050]={0};
bool nm(int x,int y,int z){
	if(x+y>z*2){
		return 1;
	}
	return 0;
}
bool mn(int i,int j,int t){
	if(b[i][j][t]){
		return 0;
	}
	if(b[i][t][j]){
		return 0;
	}
	if(b[j][i][t]){
		return 0;
	}
	if(b[j][t][j]){
		return 0;
	}
	if(b[t][j][i]){
		return 0;
	}
	if(b[t][i][j]){
		return 0;
	}
	
	return 1;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int t=0;t<n;t++){
				if(nm(a[i],a[j],a[t])&&bool(mn(i,j,t))){
					nxt++;
					b[i][j][t]==1;
					b[i][t][j]==1;
					b[j][t][i]==1;
					b[j][i][j]==1;
					b[t][i][j]==1;
					b[t][j][i]==1;
				}
			}
		}
	}
	cout<<nxt;
	return 0;
}
