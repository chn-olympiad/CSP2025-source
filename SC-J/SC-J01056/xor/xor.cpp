#include<bits/stdc++.h>
using namespace std;
int n,a[500010],n1,s;
long long k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	n1=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0) n1--;
		if(a[i]==k) s++; 
	}
	if(k==0){
		if(n1<=0){
			cout<<0;
			return 0;
		}
		if(n1!=2 && n1!=1)cout<<2*n1-4; 
		else cout<<n1*1-1;
	}
	else if(k==1){
		if(n1!=2 && n1!=1&&n%2==0)cout<<2*n1-2;
		else cout<<n1*1;
	}
	else cout<<s; 
	return 0;
} 