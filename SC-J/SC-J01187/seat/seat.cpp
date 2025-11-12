#include<bits/stdc++.h>
using namespace std;
int a[105],a1;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		 cin>>a[i];
	}
	a1=a[0];
	sort(a,a+(n*m));
	for(int i=n-1;i>=0;i--){
		if((i%2)==0){
			for(int j=m-1;j>=0;j--){
				if(a[n*m-i*m-j-1]==a1){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
		else{
			for(int j=0;j<m;j++){
				if(a[n*m-i*m-m+j]==a1){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
	}
	return 0;
} 