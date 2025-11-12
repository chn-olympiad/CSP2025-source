#include<bits/stdc++.h>
using namespace std;
int a[5050];
int main(){
	int n,k=-1,m,l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>k){
			k=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){	
		if(i!=j){
			m=m+a[i]+a[j];
			if(m>k*2){
				l+=1;
				m=0;
			}
		}}
	}
	cout<<l;
	return 0;
}