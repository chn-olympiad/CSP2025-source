#include<bits/stdc++.h>
using namespace std;
int yh(int a,int b){
	if(a|1==b|1) 
		return 0;
	else
		return 1;
}
int main(){
	freopen("xor.in.txt","r",stdin);
	freopen("xor.out.txt","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(yh(a[1],a[2])==k) cout<<1;
	else cout<<0;
	return 0;
}
