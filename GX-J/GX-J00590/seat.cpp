#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a=0;
	int h=0;
	int y=0;
	int arr[n*m];
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	int z=0;
	int ming=arr[0];
	for(int i=0;i<n*m;i++){
		for(int y=n*m-1;y>=i+1;y--){
			if(arr[y]>arr[y-1]){
				swap(arr[y],arr[y-1]);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		while(1){
			if(arr[z]==ming){
				cout<<y+1<<" "<<i+1;
				a++;
				break;
			}
			z++;
			if(h==0){
				y++;
			}else{
				y--;
			}
			if(h==0&&y==n){
				y=n-1;
				h=1;
				break;
			}else if(h==1&&y==-1){
				
				h=0;
				y=0;
				break;
			}
		}
		if(a>0){
			break;
		}
		
		
	}




	return 0;
}
