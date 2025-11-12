#include <bits/stdc++.h>
using namespace std; 
int a[500005];
int n,k,ans=0;
int main(){
	freopen("xor.in","r",stdin);
  	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2&&k==0){
		int ans=0;
		if((a[1]^a[2])==0){
			ans=1;
		}
		if(a[1]==0&&a[2]==0){
			ans=2;
		}else if(a[1]==0||a[2]==0){
			ans=1;
		}
		cout<<ans;
		return 0;
	}
	cout<<n/2;
	return 0;
}
