#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0,ans2=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a[0]=-999;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			ans++;
		}
		
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]){
				ans2++;
				a[i]-=999;
				a[i-1]-=9999;
			}
		
		}
		cout<<ans2;
	}
	if(k==1){
		
		
		cout<<ans;
	}
	return 0;
}
