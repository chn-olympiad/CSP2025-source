#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,f=1;
    int arr[500100];
    cin>>n>>k;
    for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]!=1) f=0;
	}
	if(k==0&&f==1) cout<<n;
	
    return 0;
}

