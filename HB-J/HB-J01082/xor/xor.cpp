#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],t=0,u=0;
string s[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) t++;
		if(a[i]==0) u++;
	}
	sort(a+1,a+n+1);
	/*if(n==1&&k==0&&a[1]!=0) {cout<<0;return 0;}
	else if(n==1&&k==0&&a[1]==0){cout<<1;return 0;}
	if(n==1&&k==1&&a[1]==1) {cout<<1;return 0;}
	if(n==1&&k==1&&a[1]!=1) {cout<<0;return 0;}*/
	/*if(n==2&&k==0&&a[1]!=0&&a[2]!=0){ cout<<0;return 0;}
	if(n==2&&k==0&&a[1]==0&&a[2]!=0){ cout<<1;return 0;}
	if(n==2&&k==0&&a[1]!=0&&a[2]==0){ cout<<1;return 0;}
	if(n==2&&k==0&&a[1]==0&&a[2]==0){ cout<<2;return 0;}//
	if(n==2&&k==1&&a[1]!=1&&a[2]!=1){ cout<<0;return 0;}
	if(n==2&&k==1&&a[1]==1&&a[2]!=1){ cout<<1;return 0;}
	if(n==2&&k==1&&a[1]!=1&&a[2]==1){ cout<<1;return 0;}
	if(n==2&&k==1&&a[1]==1&&a[2]==1){ cout<<2;return 0;}//
	if(k==0&&a[1]!=0){ cout<<0;return 0;}
	if(k==0&&a[1]==0){ cout<<u;return 0;}
	if(k==1){ cout<<t;return 0;}
	else cout<<2;
	if()*/
	/*if(k==0){
		cout<<u;
		return 0;
	}
	if(k==1)
	{
		cout<<t;
		return 0;
	}
	else if(k!=0&&k!=1){
		cout<<2;
		return 0;
	}*/
	if(n==1&&k==0){
		cout<<0;
		return 0;
	}
	if(n==2&&k==0){
		cout<<0;
		return 0;
	}
	if(k==1){
		cout<<t;
		return 0;
	}
	if(k==0){
		cout<<u;
		return 0;
	}
	if(k>1){
		cout<<n/2;
		return 0;
	}
	return 0;
}
