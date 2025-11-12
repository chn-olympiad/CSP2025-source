#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+5];
	int min1=1e9,max1=-1; 
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>max1)
		max1=a[i];
		if(a[i]<min1)
		min1=a[i];
	}
	if(max1==1&&min1==1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(max1==1&&min1==0){
		int s=0;
		if(k==0){
			for(int i=0;i<n;i++){
				if(a[i]==0||a[i]==1&&a[i+1]==1)
				s++;
			}
		}
		if(k==1){
			for(int i=0;i<n;i++){
				if(a[i]==1&&a[i+1]==0||a[i]==0&&a[i+1]==1)
				s++;
			}
		}
		cout<<s;
		return 0;
	}
	return 0;
}
