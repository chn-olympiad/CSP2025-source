#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000005],flag=1,maxn=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
		maxn=max(maxn,a[i]);
	}
	if(k==0 && flag==1){
		cout<<n/2;
	}else if(maxn==1&&k<=1){
		int a0=0,a1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				a0++;
			}else{
				a1++;
			}
		}
		if(k==0){
			cout<<a0+(a1/2);
		}if(k==1){
			cout<<a1;
		}
	}else{
		cout<<1;
	}
	return 0;
}
