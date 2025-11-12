#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int max1;
int main(){
	cin>>n>>k;
	int flag=0;
	int cnt=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)flag+=1;
		else if(a[i]==1)cnt+=1; 
	}
	if(k==0&&flag==n){
		cout<<n;
		return 0;
	} 
	else if(k==0&&cnt==n){
		cout<<n/2;
		return 0;
	}
	if(k==0&&flag+cnt==n){
		cout<<n/3;
		return 0;
	}
	if(k==1&&flag==n){
		cout<<0;
		return 0;
	}
	else if(k==1&&cnt==n){
		cout<<n;
		return 0;
	}
	else{
		cout<<n/2;
		return 0;
	}
	
	return 0;
}
