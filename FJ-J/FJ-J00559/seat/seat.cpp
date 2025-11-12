#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int s[10000];
	int r=1;
	int k,t;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	for(int i=1;i<n*m;i++){
		if(s[i]>s[0]){
			r++;
		}
	}
	if(r%n==0){
		k=r/n;
	}else k=r/n+1;
	if(k%2==0){
		t=k*n-r+1;
	}else t=n-(k*n-r);
	cout<<k<<" "<<t;
	return 0;
} 
