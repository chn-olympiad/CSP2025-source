#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	int ans=0;
	int a[n+5]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)ans++;
		for(int j=1;j<=i;j++){
			if(a[i]-a[j]==k)ans++;
		}
	}
	cout<<ans;
}
