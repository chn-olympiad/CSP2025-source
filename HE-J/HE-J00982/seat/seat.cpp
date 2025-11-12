#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",n,m);
	
	int zong=n*m;
	int arr[zong];
	for(int i=0;i<zong;i++){
		cin>>arr[i];
	}
	int R=arr[0];
	sort(arr,arr+zong);
	int j=1,k=0;
	for(int i=zong-1;i>=0;i--){
		
		if(j%2==0){
			k--;
			if(k<1){
				k=1;
				j++;
			}
		}else{
			k++;
			if(k>n){
				k=n;
				j++;
			}
		}
		if(arr[i]==R){
			printf("%d %d",j,k);
			return 0;
		}
		
	}
	return 0;
}
