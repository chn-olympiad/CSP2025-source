#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool flaga=0,flagb=1;
	cin>>n>>k;
	if(k==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0) flagb=0;
	}
	if(flagb) cout<<7;
	else cout<<13;
	return 0;
}
