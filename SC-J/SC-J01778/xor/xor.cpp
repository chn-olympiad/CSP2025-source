#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int f(int x,int y){
	stack<int>arr1;
	stack<int>arr2;
	int cntx1=0;
	int cntx2=1;
	int ans=0;
	if(x==0){
		int z=y;
		y=0;
		x=z;
	}
	if(x>=2){
		while(x>cntx2){
			cntx2*=2;
			cntx1++;
		}
		while(cntx1>=0){
			if(x>=cntx2){
				arr1.push(1);
				x-=cntx2;
			}else{
				arr1.push(0);
			}
			cntx1--;
			cntx2/=2;
		}
	}else{
		if(x==1){
			arr1.push(1);
		}else{
			arr1.push(0);
		}
	}
//_______________________________________________________________________
	int cnty1=0;
	int cnty2=1;
	if(y>=2){
		while(y>cnty2){
			cnty2*=2;
			cnty1++;
		}
		while(cnty1>=0){
			if(y>=cnty2){
				arr2.push(1);
				y-=cnty2;
			}else{
				arr2.push(0);
			}
			cnty1--;
			cnty2/=2;
		}
	}else{
		if(y==1){
			arr2.push(1);
		}else{
			arr2.push(0);
		}
	}
	int j=1;
	while(arr1.size()!=0||arr2.size()!=0){
		if(arr1.size()!=0&&arr2.size()!=0){
			if(arr1.top()!=arr2.top()){
				ans+=j;
			}
			j*=2;
			arr1.pop();
			arr2.pop();
		}else{
			if(arr1.size()==0){
				if(arr2.top()==1){
					ans+=j;
				}
				j*=2;
				arr2.pop();
			}
			if(arr2.size()==0){
				if(arr1.top()==1){
					ans+=j;
				}
				j*=2;
				arr1.pop();
			}			
		}
	}
	return ans;
}
int n,m;
int arr[500005]={0};
int arr2[500005]={0};
int arr3[500005]={0};
int ans_ger=0;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<=n-1;i++){
		arr2[i]=f(arr[i],arr[i+1]);
		if(arr2[i]==m)ans_ger++;
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<=i;j++){
			arr3[i]+=arr2[j];
		}
	}
	for(int l=0;l<n-1;l++){
		for(int r=n-2;r>l;r--){
			if((arr3[r]-arr3[l])==m)ans_ger++;
		}
	}
	cout<<ans_ger;
	return 0;
}
