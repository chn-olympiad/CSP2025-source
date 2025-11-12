#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans,num;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	num=max(num,a[i]);
    	ans+=a[i];
	}
	if(ans>num*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
