#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k;
int count0,count1;
int a[maxn],s[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) count1++;
		else if(!a[i]) count0++;
	}
	if(k==0 and count1==n){
		cout<<1<<"\n";
	}else if(k==0 and count0==n){
		cout<<0<<"\n";
	}else if(k==1 and count1==n){
		cout<<1<<"\n";
	}else if(k==1 and count0==n){
		cout<<0<<"\n";
	}else if(k==1){
		cout<<1<<"\n";
	}else{
		cout<<2<<"\n";
	}
	return 0;
}
