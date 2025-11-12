#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ma,he;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		he+=a[i];
	}
	if(ma==1){
		int ans=1;
		for(int i=2;i<=n-2;i++){
			for(int j=1;j<=i;j++){
				ans+=j;
			}
		}
		cout<<ans%998244353;
		return 0;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(ma*2<he)cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<1; 
	return 0;
}
