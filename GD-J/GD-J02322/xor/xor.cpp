#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100008],c=0,d=11451414,ans=0,bns=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c=max(a[i],c);
		d=min(a[i],d);
		if(a[i]==0)ans++;
		if(a[i]==1)bns++;
	}
	if(k==0&&c==1&d==1){
		int p=bns/2;
		cout<<p;
		return 0;
	}
	if(k==0&&c==1&d==0){
		int p=ans+bns/2;
		cout<<p;
		return 0;
	}
	if(k==1&&c==1&d==1){
		int p=bns/2;
		cout<<p;
		return 0;
	}
	if(k==1&&c==1&d==0){
		int p=bns;
		cout<<p;
		return 0;
	}
	return 0;
} 
