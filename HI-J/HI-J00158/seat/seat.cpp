#include<bits/stdc++.h>
using namespace std;
int a[11][11]={},b[1000]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	sort(b,b+n*m+1);
	
	int s=b[1];
	
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2 !=0){
		
		for(int j=1;j<m;j++){
			a[i][j]=b[k];
			k++;
		}
	}else if(i%2==0){
		for(int j=1;j<=m;j++){
			a[i][j]=b[k];
		}
	}
	}
	for(int i=n;i>=1;i--){
		
		for(int j=m;j>=1;j--){
			if(a[i][j]==s){
		
			cout<<i<<j;
	}
	}
}

// 2 2 99 100 97 98
	return 0;
} 
