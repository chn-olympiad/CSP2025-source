#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int a1=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m-i-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i*m+j]==a1){
				if(i%2==0){	
					cout<<(i+1)<<' '<<(j+1);
				}
				else{
					cout<<(i+1)<<' '<<(n-j+1);
				}
			}
		}
	}
}

