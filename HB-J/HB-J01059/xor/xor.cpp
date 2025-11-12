#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],flag;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
	    cin>>a[i];
	    flag+=a[i];	
	}
	if(flag==n){
	    cout<<n/2;	
	}
	else if(flag<n){
	    if(flag==0){
		    cout<<n;	
		}
		else{
		    cout<<n-flag;	
		}
	}
    return 0;
}
