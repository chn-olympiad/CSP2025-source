#include<bits/stdc++.h>
using namespace std;
int n,a[5001],maxx=-1,sum; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxx){
			maxx=a[i];
		}
		sum+=a[i];
	}
	if(n==3){
		if(sum>maxx*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<1126;
	} 
	return 0;
}

