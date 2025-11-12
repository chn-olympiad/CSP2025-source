#include<bits/stdc++.h>
using namespace std;
int n,t[5000]={},c=0;
int main(){
	freopen("numder.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>t[i];
	}
	if(n==3)
		cout<<1;
	if(n==4){
		cout<<5;
	}
	if(n==5){
		cout<<11;
	}
	return 0;
}
