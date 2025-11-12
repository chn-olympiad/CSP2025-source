#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int num=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i-1]==a[i]&&a[i]==1){
				ans++;
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			if(!a[i]){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}