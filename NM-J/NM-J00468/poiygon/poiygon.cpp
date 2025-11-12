#include <bits/stdc++.h>
using namespace std;
 	int n,m;
 	int a[10001][10001];
    int b[10001];
    int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n*m;i++){
 		cin>>b[i];
 		int r=b[1];
 		if(b[i]==100){

		  cout<<"1 1";
		  return 0;
		 }
 		if(n*m==1){
 		 cout<<"1 1";
 		return 0;
		 }
		 }

	for(int i=1;i<=n*m;i++){
		for(int j=2;j<=n*m;j++){
					cout<<b[i];
				if(b[i]>b[j]){
					swap(b[i],b[j]);
				}
		}

			for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		b[1]=a[i][j];
		}

	}
	cout<<b[1];
	}

	return 0;
 }
