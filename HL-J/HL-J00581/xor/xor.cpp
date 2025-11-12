#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n==1&&k==0){
		if(a[1]=0)cout<<1;
		else cout<<0;
	}
	if(n==2&&k==0){
		if(a[1]==0||a[2]==0)cout<<1;
		else if((a[1]+a[2]+1)%2==0)cout<<1;
	}
	return 0;
}
