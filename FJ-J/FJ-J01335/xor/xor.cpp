#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=0;
	if(k==1){
		for(int i=0;i<n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
	}else if(k==0){
		int b=1;
		for(int i=0;i<n;i++){
			if(a[i]==0){
				b=0;
				break;
			}
		}
		if(b==1){
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++) ans++;
			}
		}else{
			for(int i=0;i<n;i++){
				for(int j=i;j<n&&a[i]!=1;j++) ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}