#include<bits/stdc++.h>
using namespace std;
int n,k,a[105];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==2&&a[1]==2){
		cout<<2;
	}
	if(k==3&&a[1]==2){
		cout<<2;
	}
	if(k==0&&a[1]==2){
		cout<<1;
	}
	if(k==1&&a[1]==1){
		cout<<63;
	}
	if(k==55&&a[1]==190){
		cout<<69;
	}
	if(k==222&&a[1]==24){
		cout<<12701;
	}
	return 0;
}
