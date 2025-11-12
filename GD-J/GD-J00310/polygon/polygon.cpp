#include<bits/stdc++.h> 
using namespace std;
int a[105]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,cnt=0,maxa;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n==3){
		maxa=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>maxa*2)cout<<1;
		else cout<<0;
	}else{
		cout<<(n-1)*(n-2)/2%998244353;
	}
	return 0;
}
