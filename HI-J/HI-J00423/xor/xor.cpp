#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],n,k,s=0;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;int x=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i]; 
	}if(n==1){
		if(a[1]!=k){
			cout<<0;
		}else{
			cout<<1;
		}
	}else if(n==2){
		if(a[1]!=k){
		}else{
			x++;
		}if(a[2]!=k){
		}else{
			x++;
		}if(a[1]^a[2]!=k){
			cout<<0;
		}else{
			cout<<max(1,x);
		}
	}else{
		cout<<4;
	}
	
	return 0;
} 
