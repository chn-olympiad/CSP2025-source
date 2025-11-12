#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	int useds[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
		useds[i]=0;
	}
	int lr=0;
	if (k==1) {
		for (int i=0;i<n;i++){
			if (a[i]==1){
				lr++;
			}
		}
		if (lr%2==0) lr-=1;
		cout<<lr;
		return 0;
	} else if (k==0){
		for (int i=0;i<n;i++){
			if (a[i]==1){
				lr++;
			}
		}
		if (lr==0) {
			for (int i=0;i<n;i++){
				if (a[i]==0) {
					lr++;
				}
			}
		} else if(lr%2==1) lr-=1;
		cout<<lr;
		return 0;
	}
	for (int i=0;i<n;i++){
		if (a[i]==k){
			lr=max(lr,1);
		}
		if (useds[i]==1) continue;
		int ls=a[i];
		for (int j=i+1;j<n;j++){
			if (useds[j]==1){
				break;
			}
			ls^=a[j];
			if (ls==k){
				lr=max(lr,j-i);
			}
		}
	}
	cout<<lr;
	return 0;
}
