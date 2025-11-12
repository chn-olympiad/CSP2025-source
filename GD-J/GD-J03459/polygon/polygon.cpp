#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000008],b[1000008];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3) cout<<0;
	else{
		if(a[1]+a[2]+a[3]>max(a[3],max(a[1],a[2]))*2){
			cout<<1;
		}
		else cout<<0;
	}
} 
