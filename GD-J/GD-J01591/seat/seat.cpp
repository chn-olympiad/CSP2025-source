#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[1001]={0};
int num=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n][m]={0};
	int c=n*m;
	for(int i=0;i<c;i++){
		cin>>b[i];
	}
	int a1=b[0];
	sort(b,b+c);
	int d=c-1;
	for(int i=0;i<c;i++){
		int l=i/n;
		if(l%2==0) a[i%n][l]=b[d];
		else a[n-(i%n)-1][l]=b[d];
		d--;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==a1){
				cout<<j+1<<" "<<i+1;
			}
		}
	}
	return 0; 
} 
