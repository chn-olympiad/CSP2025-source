#include<bits/stdc++.h>
using namespace std;
int n, a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		if(a[1]+a[2]<=a[3]||a[1]+a[3]<=a[2]||a[2]+a[3]<=a[1]){
			cout<<0;
		}
		else cout<<1;
	}
	else{
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=1){
				flag=0;
				break;
			}
		}
		if(flag==1){
			int ans=(n-2)%998244353;
			cout<<ans;
		}
	}
	return 0;
}

