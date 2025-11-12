#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,ans=0;
	cin>>n;
	int a,b;
	for(int i=0;i<=n;i++){
		b=a;
		cin>>a;
		if(a>1){
			cout<<0;
			return 0;
		}
		if(a!=b) ans++;
	}
	cout<<ans;
	return 0;
	
} 
