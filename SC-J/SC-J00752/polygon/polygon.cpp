#include<bits/stdc++.h>
using namespace std;
int n=0;
int a[5005]={0};


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	if(n==3&&a[2]<a[0]+a[1]){
		cout<<1;
	}else{
		if(a[2]>=a[0]+a[1]) cout<<0;
	}
	return 0;
} 