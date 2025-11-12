#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,c,r,a[101];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	if(n*m==1){
		cout<<1<<' '<<1;
		return 0;
	}
	int z;
	z=a[0];
	for(int i=1;i<n*m;i++){
		if(a[i-1]<a[i]){
			int c;
			c=a[i];
			a[i]=a[i-1];
			a[i-1]=c;
		}
	}
	int u=0;
	for(int i=1;i<=n;i++){ 
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[u]==z){
					cout<<i<<' '<<j;
					break;
				}
				u++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[u]==z){
					cout<<i<<' '<<j;
					break;
				}
				u++;
			}
		}
	}
	return 0;
}
