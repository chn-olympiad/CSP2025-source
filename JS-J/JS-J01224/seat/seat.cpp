#include <bits/stdc++.h>
using namespace std;
int cs[15][15],arr[101],m,n,R,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
		cin>>arr[i];
	R=arr[1];
	for(int i=1;i<=m*n;i++){
		if(arr[i+1]>arr[i])
			swap(arr[i],arr[i+1]);
	}
	int i=1,j,cnt=1;
	while(i<=m){
		if(i%2){
			j=1;
			cs[i][j]=arr[cnt];
			j++;
			cnt++;
			if(j==n){
				i++;
			}
		}
		else{
			j=n;
			cs[i][j]=arr[cnt];
			j--;cnt++;
			if(j==0){
				i++;
			}
	
			}
		}
	int c,r; 
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			if(cs[i][j]==R){
				c=i;r=j;
			}
	}
	cout<<c<<r;
	return 0;
}
