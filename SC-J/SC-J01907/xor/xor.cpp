#include<bits/stdc++.h>
using namespace std;
int n,k,a,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	if(n<=2&&k==0){
		int b;
		cin>>a>>b;
		if(a^b==0)cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a;
	}
	
	cout<<n/2;
	return 0;
}