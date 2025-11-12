#include<bits/stdc++.h>
using namespace std;int a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0){int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else{
				if(a[i-1]==a[i]){
					ans++;
					i++;
				}
			}
		}cout<<ans;
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}cout<<ans;
	}
	return 0;
}
