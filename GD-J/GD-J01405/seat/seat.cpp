#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,a;
	cin>>n,m;
	int arr[n][m];
	int ar[a];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		cin>>arr[i][j];
		}
	}
		for(int i=0;i<n;i++){
			cin>>ar[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j];
			}
		}
	
	return 0;
}
