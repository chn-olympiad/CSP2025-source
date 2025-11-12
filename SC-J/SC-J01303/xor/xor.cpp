#include<iostream>
#include<cstdio>
using namespace std;
int n,k,s1,s0,a[100001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
		if(a[i]==1){
			s1++;
		}if(a[i]==0){
			s0++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			if(a[i+1]==1){
				s0++;
				i++;
				continue;
			}
		}
	}
	if(n==1&&k==0&&flag==1){
		cout<<0;
		return 0;
	}else if(n==2&&k==0&&flag==1){
		cout<<1;
		return 0;
	}else if(n<=100&&k==0&&flag==1){
		cout<<n/2;
	}else{
		if(k==1){
			cout<<s1;
		}else if(k==0){
			cout<<s0;
		}
	}
	return 0;
}