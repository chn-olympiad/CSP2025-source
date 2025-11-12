#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,me;
	cin>>n>>m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int arr[n][m],arr1[n*m];
	for(int i=0;i<n*m;i++){
		cin>>arr1[i];
	}
	me=arr1[0];
	sort(arr1,arr1+n*m);
	int m1=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			arr[i][j]=arr1[m*n-m1-1];

			m1++;
		}	
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==me) {
			cout<<i+1<<" "<<j+1;
			return 0;
			}
		}
		
	}
	return 0;
}
