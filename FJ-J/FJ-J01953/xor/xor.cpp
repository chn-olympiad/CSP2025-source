#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,k,a[200005],l=0;
int main(){
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			l=1;
		}
	}
	if(l==0){
		cout<<n/2;
	}
	int sum=0;
	if(l==1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					sum++;
				}
			} 
			cout<<sum;
		} 
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum++;
				}
				if(a[i]==1&&a[i+1]==1){
					sum++;
					i++;
				}
			} 
			cout<<sum;
		}
	}
	return 0;
} 
