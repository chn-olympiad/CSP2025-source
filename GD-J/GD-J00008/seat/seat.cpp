#include<bits/stdc++.h>
using namespace std;
int n,m,k,l,h;
int arr[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>arr[i];
	k=arr[1];
	for(int i=1;i<=n*m-1;i++){
		for(int j=1;j<=n*m-1;j++){
			if(arr[j]<arr[j+1]){
				int x=0;
				x=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=x;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(arr[i]==k){
			l=i/n+1;
			if(i%n==0) l--;
			if(l%2!=0){
				h=i%n;
				if(i%n==0)	h=n;
			}
			else{
				h=n-i%n+1;
				if(i%n==0)h=0;
			}
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
