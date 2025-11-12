#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int i;
	cin>>i;
	while(i){
		int n;
		cin>>n;
		int arr[n+3][n+3]={};
		int arr1[n+3][n+3]={};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>arr[j][i];
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				int sum=0;
				if(sum<=n/2&&arr[i][j]>arr[i][j+1]){
					arr1[i][j+1]=arr[i][j];
				}
			}
		}
		cout<<arr[1][n]+arr[2][n]+arr[3][n];
	}
	return 0;
}
