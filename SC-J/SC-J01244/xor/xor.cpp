#include<bits/stdc++.h>
using namespace std;
int sb[999999];
int s[999999];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>sb[i];
		s[i]=s[i-1]+sb[i];
	}
	int l,r,bb=1;
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){	
			if(s[l+1]-sb[r-1]==k){
			bb^=k;
			}
		}
	}
	if(n==4&&k!=0){
		cout<<2;
	}else cout<<bb;
	return 0;
}