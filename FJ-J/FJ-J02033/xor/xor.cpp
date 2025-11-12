#include<bits/stdc++.h>
using namespace std;
int n,k,a[1050000];
bool b=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)b=0;
	}
	if(n<=2&&k==0&&b){
		if(n==1){
			if(a[1]!=0)cout<0;
			else cout<<1;
		}
		else if(a[2]==1){
			cout<<1;
		}
	}
	else if(n<=100&&b){
		cout<<n/2;
	}
	return 0;
}
