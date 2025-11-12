#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],a1[105],b[15][15],sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--) a1[n*m-i+1]=a[i]; 
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				b[i][j]=a1[(i-1)*m+j];
				if(b[i][j]==sum){
					cout<<i<<" "<<j<<endl;
				}
			}
		} else{
			for(int j=m;j>=1;j--){
				b[i][j]=a1[(i-1)*m+m-j+1];
				if(b[i][j]==sum){
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
	/*
	T2也还好
	应该能过 
	*/
	return 0;
}
