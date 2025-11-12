#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			else if(a[i]==a[i+1]==1) ans++,i++;
		}
		cout<<ans;
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
	}
	else cout<<n;
	return 0;
} 
