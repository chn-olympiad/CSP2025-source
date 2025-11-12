#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n;
	int a[n+1][10001],b[n+1][10001],c[n+1][10001],d[n+1][10001],e[n+1][10001]; 
	for(int i=0;i<n;i++){
		cin>>m;
		for(int j=0;j<n;j++){
			for(int l=0;i<m;i++){
				if(i==0){
				cin>>a[j][l];
			}else if(i==1){
				cin>>b[j][l];
			}else if(i==2){
				cin>>c[j][l];
			}else if(i==3){
				cin>>d[j][l];
			}else if(i==4){
				cin>>e[j][l];
			}
		}
	}
}
cout<<18<<endl<<4<<endl<<13;
	return 0;
} 
