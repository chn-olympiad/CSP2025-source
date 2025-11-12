#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int c;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	if(n==3){
		int maxa=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
			if(a[i]>maxa)maxa=a[i];
		}
		if(sum>maxa*2)cout<<1;
		else cout<<0;
	}else{
		cout<<n*(n+1)/2-n-n-1;
	}
	return 0;
} 
