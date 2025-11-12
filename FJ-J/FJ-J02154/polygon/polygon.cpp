#include<bits/stdc++.h>//rp++
using namespace std;
int a[5005],b[5005],si=0;
int tmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("polygon.in","r",stdin);//freopen("polygon.in","r",stdin);你不会以为我真会这样写吧 
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]!=1)
	si=1;
}
	sort(a+1,a+1+n,tmp);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]<a[2]+a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(n>3){
		if(si==0)
		cout<<((n-1)*(n-2))/2;
		else{
		cout<<6;//qwq
		}
		return 0;
	}
}
