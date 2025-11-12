#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	int maxa=0;
	for(int i=1;i<=n;i++){
		if(a[i]>maxa){
			maxa=a[i];
		}
	}
	if(s>maxa*2){
		cout<<1;
	}
	else
	    cout<<0; 
	
	return 0;
}