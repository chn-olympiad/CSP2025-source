#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<2){
		if(a[1]==a[2]&&a[1]==k) cout<<2;
		else cout<<0;
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
