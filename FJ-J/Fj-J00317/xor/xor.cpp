#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,a[50001],a1[50001],z=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a1[i]=0;
	}
	for(int j=0;j<n;j++){
			if(a[j]==k){
			z++;
			a1[j]=1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=n-i;j++){
		
int ls2=0;
for(int l=j;l<j+i;l++){
	if(a1[l]==1){
		ls2=1;
		break;
	}
}
if(ls2==0){
	int ls;
	ls=a[j];
	for(int l=1;l<i;l++){
		ls ^= a[j+l];
	}
	if(ls==k){
		z++;
		for(int l=j;l<j+i;l++){
			a1[l]=1;
		}
	}
}
			
		}
	}
	cout<<z;
	return 0;
}
