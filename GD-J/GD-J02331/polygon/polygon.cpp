#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,maxl=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxl=max(a[i],a[i-1]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(sum>2*maxl){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	
	
	return 0;
} 
