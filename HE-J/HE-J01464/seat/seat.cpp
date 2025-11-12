#include<bits/stdc++.h>
using namespace std;
int p[101];
int pp[101];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int r=0;
	int k=1;
	int zq=0; 
	cin>>n>>m;
	int a[n][m];
	for(int i=1;i<=n*m;i++){
		cin>>p[i];
		r=p[1];
	}
		for(int i=1;i<=n*m;i++){
		for(int j=1;j<=i;j++){
			if(p[i]<p[i+1]) {
				pp[i]=p[i];
				p[i]=pp[i+1];
				p[i]=pp[i];
			}
			if(p[j+1]<p[j+2]){
				pp[j+1]=p[j];
				p[j+1]=p[j+2];
				p[j+1]=pp[j+1];
			}
		} 
	}
	int l=1;
	while(l!=m){
	for(int i=1;i<=n*m;i++){
		while(zq=0){
			a[k][l]=p[i];
			if(r=a[k][l]){
				cout<<k<<" "<<l;
				return 0;
			}
			k++;
			if(k=n){
				zq=1;
				l++;
			}
		}
		while(zq=1){
			a[k][l]=p[i];
			if(r=a[k][l]){
				cout<<k<<" "<<l;
				return 0;
			}
			k--;
			if(k=1){
				zq=0;
				l++;
			}
		}
		}
	}
	return 0;
	}
