#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int f=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(n==3){
		if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(f==0){
		long long ans=0;
		int op=n-2;
		for(int i=1;i<=n-2;i++){
			ans+=i*op;
			op--;
		}
		cout<<ans;
	}
	return 0;
}