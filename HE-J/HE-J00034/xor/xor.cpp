#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n,m,s,c=1,y;
	const int maxn=1000000;
	cin>>n>>m;
	int a[n];
	int b[n][100000];
	int r[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		while(c=0){
			c=a[i]/2;
			s=a[i]%2;
			b[i][r[i]]=s;
			if(c==0) break;
			r[i]++;
		}
		
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<max(r[i],r[i+1]);j++){
			if(b[i][j]+b[i+1][j]==1) y++; 
		}
	}	
	return 0;
}
