#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],dex,flag,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(dex=0;dex<n;dex++){
			if(a[dex]==0){
				flag=0;
				ans++;
			}
			else if(a[dex]==1){
				if(flag==0){
					flag=1;
				}
				else{
					flag=0;
					ans++;
				}
			}
		}
	}
	else if(k==1){
		for(dex=0;dex<n;dex++){
			if(a[dex]==1){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
