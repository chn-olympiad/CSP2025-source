#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans,n,a[50010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
	cout<<0;
	return 0;
	}
	if(a[1]+a[2]<=a[3]||a[2]+a[3]<=a[1]||a[1]+a[3]<=a[2]){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}
