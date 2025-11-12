#include<bits/stdc++.h>
using namespace std;
int arr[105];
int mp[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a = n*m;
	for(int i=1;i<=a;i++){
		cin>>arr[i];
	}
	int cnt = arr[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-1;j++){
			if(arr[j] < arr[j+1]) swap(arr[j],arr[j+1]);
		}
	}
	int sum = 1;
	int left = 1;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=n;j++){
			mp[j][left] = arr[sum];
			sum++;
			if(sum == a) break;  
		}
		left++; 
		for(int j=n;j>=1;j--){
			mp[j][left] = arr[sum];
			sum++;
			if(sum == n*m) break;  
		}
		left++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j] == cnt){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
