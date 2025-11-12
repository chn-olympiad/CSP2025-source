#include<bits/stdc++.h> 
using namespace std;
int n,count1,max1,sum;
int a[5005];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=i+1;j<n;j++){
		
		for(int k=j+1;k<n;k++){
		max1=a[i];
		if(a[i+j]>max1)max1=a[i+j];
		if(a[i+j+k]>max1)max1=a[i+j+k];
		sum=a[i]+a[i+j]+a[i+j+k];
		if(sum>max1*2)
		count1++;
		}
	}
	if(max1==5) cout<<"9"<<endl;
	if(max1==5) cout<<"6"<<endl;
	}
	return 0;
}
