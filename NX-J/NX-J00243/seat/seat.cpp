#include<bits/stdc++.h>
using namespace std;
int y[2]={1,-1};
bool cmp(int a,int b){
	return b<a;
}
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long arr[n+10][m+10]={0};
	long long arr1[n*m+10];
	for(int i=0;i<n*m;i++){
		cin>>arr1[i];
	}
	long long r=arr1[0],k=0,i=1,j=1,flag=1,x=0;
	sort(arr1,arr1+n*m,cmp);
	///cout<<arr1[0]<<" "<<r<<endl;
	while(arr1[k]!=r){
		arr[i][j]=arr1[k];
		///cout<<i<<" "<<j<<" "<<k<<endl; 
		k++;
		if(flag==1){
			if(i+1<=n){
				i+=y[x];
			}else{
				x=1;
				j++;
				flag=0;
			}
		}else{
			if(i-1>=1){
				i+=y[x];
			}else{
				x=0;
				j++;
				flag=1;
			}
		}
	}
	cout<<j<<" "<<i<<endl;
	return 0;
}
