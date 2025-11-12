#include<bits/stdc++.h>
using namespace std;
int n,k,s=0,ss=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			s++;
		}
		if(a[i]==0){
			ss++;
		}
	}
	if(k==0){
		cout<<ss;
		return 0;
	}
	if(k==1){
		cout<<s;
		return 0;
	}
	s=0;
	ss=0;
	for(int i=0;i<n;i++){
		s=s+a[i];
		if(s>=k){
			ss++;
			s=0;
		}
	}
	cout<<ss;
	return 0;
} 
