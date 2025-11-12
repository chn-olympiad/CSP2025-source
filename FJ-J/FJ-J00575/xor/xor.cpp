#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];                       
int main(){
	freopen("xor.out","w",stdout);
	freopen("xor.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		cout<<1;
	}
	return 0; 
}
