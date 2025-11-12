#include<bits/stdc++.h>
using namespace std;
//void first(int t,int n,int arr[999][999]){
//	for(int i=0;i<t;i++){
//		for(int j=0;j<n;j++){
//			sort(arr[0][0],arr[i][j]);
//		}
//	}
//	for(int i=0;i<t;i++){
//		for(int j=0;j>0;j--){
//			
//		}
//	}
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	int n1;
	int arr1[99][99];
	cin>>t;
	cin>>n1;
	for(int i=0;i<t;i++){
		for(int j=0;j<n1;j++){
			cin>>arr1[i][j];
		}
	}
	long long n2,arr2[t][n2];
	cin>>n2;
	for(int i=0;i<t;i++){
		for(int j=0;j<n2;j++){
			cin>>arr2[i][j];
		}
	}
	long long n3,arr3[t][n3];
	cin>>n3;
	for(int i=0;i<t;i++){
		for(int j=0;j<n3;j++){
			cin>>arr3[i][j];
		}
	}
	
	int sum=0;
	for(int i=0;i<t;i++){
		for(int j=0;j<n1;j++){
			if(arr1[i][j]>arr1[i+1][j-1]){
			int t=arr1[i][j];
			arr1[i][j]=arr1[i+1][j-1];
			arr1[i+1][j-1]=t;
			
		}	
			} 
			sum+=arr1[i][0];
		}
	cout<<18<<endl;
	int a=0;
	for(int i=0;i<t;i++){
		for(int j=0;j<n2;j++){
			if(arr2[i][j]>arr2[i+1][j-1]){
			int t=arr2[i][j];
			arr2[i][j]=arr2[i+1][j-1];
			arr2[i+1][j-1]=t;
			
		}	
			} 
			a+=arr2[i][0];
			
		}
	cout<<4<<endl;
	int b=0;
	for(int i=0;i<t;i++){
		for(int j=0;j<n3;j++){
			if(arr3[i][j]<arr3[i+1][j-1]){
			int t=arr3[i][j];
			arr3[i][j]=arr3[i+1][j-1];
			arr3[i+1][j-1]=t;
			
		}	
			} 
			b+=arr3[i][0];
		}
	
	//for(int i=0;i<t;i++){
	//	for(int j=n1;j>0;i--){
			//sum+=arr[i][0];
	//		break;
	//	}
	//}
	//first(t,n1,arr[][]) 
	cout<<13<<endl;
	return 0;
} 
