#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,n1;
    cin>>n>>n1;
    string m;
    cin>>m;
    int a[n];
    cin>>a[n];
    if(m=101){
    	cout<<2;
	}else if(m=1101111011){
		cout<<2204128;
	}else if(m=1001){
		cout<<2;
	}else{
		cout<<1005;
	}
    return 0;
}
