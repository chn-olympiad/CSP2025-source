#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		int ans=0;
		for(i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		int ans=0;
		for(i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			if(a[i]==a[i+1]&&a[i]!=0){
				a[i]=-1,a[i+1]=-1;
				ans++;
			}
		}
		cout<<ans; 
	}
	return 0;
} 
