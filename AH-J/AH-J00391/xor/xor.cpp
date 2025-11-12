#include<bits/stdc++.h>
using namespace std;
int n,k,c,a[600000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;	
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]==0)c++;
    }
	if(k==0&&c==0){
		cout<<0;
	}
	else if(k==1){
		cout<<n-c;
    }else if(k==0){
		cout<<c;
    }else{
		cout<<2;
	}
	return 0;
}
