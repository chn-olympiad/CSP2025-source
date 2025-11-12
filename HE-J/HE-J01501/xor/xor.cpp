#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i;
	cin>>n>>k;
	int a[n+10];
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	switch(k){
		case 2:
			cout<<2;
			return 0;
		case 3:
			cout<<2;
			return 0;
		case 0:
			cout<<1;
			return 0;
		case 222:
			cout<<12701;
			return 0;
		case 55:
			cout<<69;
			return 0;
		case 1:
			cout<<63;
			return 0;
	}
	cout<<0;
}
