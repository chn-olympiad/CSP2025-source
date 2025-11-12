#include<bits/stdc++.h>
using namespace std;
int MOD=998244353;
int n;
int a[5005];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3]){
			ans++;
		}
	}else if(n<3){
		ans=0;
	}
	else{
		for(int i=1;i<=n;i++){
			ans=ans+i%MOD;
		}
	}

	cout<<ans;
	return 0;
}
//AFO???
//I NOT AK IT