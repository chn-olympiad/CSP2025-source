#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0) cout<<n/2;
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
	}
	else{
		int C=a[1];
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
				C=a[i+1];
				continue;
			}
			C^=a[i];
			if(C==k){
				ans++;
				C=a[i+1];	
			}
		}
	}
	cout<<ans;
	return 0;
}
