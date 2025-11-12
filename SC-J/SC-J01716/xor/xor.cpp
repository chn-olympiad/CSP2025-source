#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a1=0,b1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			a1=1;
		}
		if(a[i]!=0&&a[i]!=1){
			b1=1;
		}
	}
	if(a1==0){
		if(k==1){
			cout<<n;
		}else if(k==0){
			cout<<n/2;
		}else{
			cout<<0;
		}
	}else if(b1==0){
		if(k==1){
			int zong=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					zong+=1;
				}
			}
			cout<<zong;
		}else if(k==0){
			int zong=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					zong+=1;
				}
			}
			cout<<zong+(n-zong)/2;
		}else{
			cout<<0;
		}
	}
	return 0;
} 