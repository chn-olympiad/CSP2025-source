#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){ //~
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k; cin>>n>>k; bool f=true,f1=true,f2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=false;
		if(a[i]!=0)f1=false;
		if(a[i]!=1&&a[i]!=0)f2=false;
	}
	if(f){
		if(k==1)cout<<n;
		else cout<<n/2;
	}
	else if(f1){
		if(k==0)cout<<n;
		else cout<<0;
	}
	else if(f2){
		if(k==0){
			int c=0,c1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)c++;
				else if(a[i]==0)c1++;
			}
			cout<<c1+c/2;
		}
		else{
			int c=0,c1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)c++;
			}
			cout<<c;
		}
	}
	return 0;
} 
