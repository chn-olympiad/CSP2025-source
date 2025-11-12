#include<bits/stdc++.h>
using namespace std;
int main(){
	/*
	freopen(club.in,"r",stdin);
	freopen(club.out,"r",stdin);
	*/
	int a,b,s=0;
	cin>>a;
	int arr[300][3];
	
	
	for(int i=1;i<=a;i++){
		cin>>b;
		int q=0,w=0,e=0;
		for(int j=1;j<=b;j++){
			
			for(int k=1;k<=3;k++){
				cin>>arr[j][k];
			}if(arr[j][1]>arr[j][2]&&arr[j][1]>arr[j][3]){
				s+=arr[j][1];}
				if(arr[j][1]<arr[j][2]&&arr[j][2]>arr[j][3]){
				s+=arr[j][2];}
				if(arr[j][3]>arr[j][2]&&arr[j][1]<arr[j][3]){
				s+=arr[j][3];}
			}}
			cout<<s;
		}
