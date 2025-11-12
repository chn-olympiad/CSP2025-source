#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	int m,n,c,r;
	cin>>n>>m;
	int a=m*n;
	int arr[1000];
	for(int i=0;i<a;i++){
		cin>>arr[i];
	}
	for(int i=0;i<a;i++){
		if(arr[i]==100){
			c=1;
			r=1;
		}
		if(arr[i]>arr[i+1]){
			c+=2;
			break;
		}else if(arr[i+1]/2==0){
				c+=1;
			}
		else{
			r+=1;
		}
		
	}
	cout<<c<<" "<<r;
	return 0;
}
