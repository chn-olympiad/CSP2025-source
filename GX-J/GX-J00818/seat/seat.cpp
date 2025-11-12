#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in",'w',stdin);
	freopen("seat.out",'r',stdout);
	int n,m,r;
	cin>>n>>m;
	int a[m+1][n+1],b[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	r=b[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-i;j++){
			if(b[j+1]>=b[j]){
				int d=b[j];
				b[j]=b[j+1];
				b[j+1]=d;
			}
		}
	}
	int s=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s++;
				a[i][j]=b[s];
			}
		}else{
			for(int j=n;j>=1;j--){
				s++;
				a[i][j]=b[s];
			}
		}
	}
	int f=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==r){
				cout<<i<<' '<<j;
				f=0;
				break;
			}
		}
		if(f==0){
			break;
		}
	}
	return 0;
}
