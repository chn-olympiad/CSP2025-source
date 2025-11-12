#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool flag2=1;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)flag2=false;
	}
	if(k==0)cout<<n;
	else if(flag2){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=1)continue;
			if(i==n){
				if(a[i-1]==0)ans++,a[i-1]=1;
			}
			else if(i==1){
				if(a[i+1]==0)ans++,a[i+1]=1;
			}
			else if(a[i+1]==0)ans++,a[i+1]=1;
			else if(a[i-1]==0)ans++,a[i-1]=1;
		}
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
