#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int b[121];
int cmp(int x0,int x2){
	return x2<x0;
}
int sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	sum=b[0];
	sort(b,b+n*m,cmp);
	for(int i=0;i<=120;i++){
	//	cout<<b[i]<<" ";
	}	
	int k=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=b[k];
				k++;
			//	cout<<a[j][i]<<" ";
			}
		//	cout<<endl;
		}
		else{
			for(int j=n;j>=1;j--){
				a[j][i]=b[k];
				k++;
			//	cout<<a[j][i]<<" ";
			}
		//cout<<endl;
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		//	cout<<a[i][j]<<" ";
			if(a[i][j]==sum){
				cout<<j<<" "<<i;
				break;
			}
		}
		//cout<<endl;
	}
	return 0;
} 
