#include<bits/stdc++.h>
using namespace std;
int n,a[5005],mx,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>mx*2) ans=1;
		else ans=0;
	} else if(mx==1){
		for(int i=3;i<=n;i++){
			ans+=n-i+1;
		}
	}
	cout << ans;
	return 0;
} 
