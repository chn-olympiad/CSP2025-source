#include <bits/stdc++.h>
using namespace std;
int arr[105],z;
bool nmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w".stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	z=arr[0];
	sort(arr,arr+n*m,nmp);
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				if(arr[i*m+j]==z){
					cout<<i+1<<" "<<j+1;
				}
			}
		}else{
			for(int j=n-1;j>=0;j--){
				if(arr[i*m+n-j-1]==z){
					cout<<i+1<<" "<<j+1;
				}
			}
		}
	}
	return 0;
}
