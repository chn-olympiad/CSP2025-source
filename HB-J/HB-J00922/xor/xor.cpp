#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    int a[n+5];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    int b=a[0],c=0;
    for(int i=1;i<n;i++){
    	if(b==k){
    	    c++;
    	    b=a[i];
    	}
    	else b=b+b^a[i];
    }
    cout<<c;
    return 0;
}
