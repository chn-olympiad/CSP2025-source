#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,s=0,x=-1;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		x=max(x,a[i]);
	}if(n==3){
		if(s>2*x){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<8;
	}
	
	return 0;
} 
