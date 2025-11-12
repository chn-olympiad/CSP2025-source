#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,mx;
int main(){
	freopen("polygon.cpp","r",stdin);
	freopen("polygon.cpp","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3]))ans++;
		cout<<ans;
		return 0;
	}
	if(mx==1){
		for(int i=3;i<=n;i++){
			for(int j=n-i+1;j>=1;j--){
				ans+=j*(j+1)/2;
				ans%=998244353;
			}
		}
		cout<<ans;
	}
	return 0;
}