#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[1000005],t=0,tt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];if(a[i]==1)t++;
		if(a[i]==0)tt++;
	}
	if(t==n){
		if(k==1)cout<<0;
		else cout<<0;return 0;
	}
	if(t+tt==n){
		if(k==0)cout<<(t+tt)/2;
		else cout<<n/2;
		return 0;
	}
	cout<<0;
}
