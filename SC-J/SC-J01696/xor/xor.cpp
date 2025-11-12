#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    int a[n];
    cin>>n>>k;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	if(n<=2 && k==0){
		if(a[1]==1){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	
	
	return 0;
}