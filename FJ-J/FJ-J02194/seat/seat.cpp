#include <bits/stdc++.h>
using namespace std;
int n,m,hang,lie,wei=0;
int a[1001],b[11][11];
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	
	int v;
	cin>>n>>m;
	for(int i=0;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n*m-1;i++){
		for(int j=0;j<=n*m;j++){
			if(a[wei]<a[wei+1]) wei+=1;
			if(a[j]<a[j+1]){
				v=a[j];
				a[j]=a[j+1];
				a[j+1]=v;
			}
		}
	}
	for(int i=wei;i==wei;i++){
		
			lie=i/n+1; 

			if(lie%2==1) hang=i%n+1;
			else if(lie%2==0) hang=n-i%n;
			cout<<lie<<" "<<hang;
			
		
	}
	