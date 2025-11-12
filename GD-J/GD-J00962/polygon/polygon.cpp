#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,a[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int mx=-1,alln=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
		alln+=a[i];
	}
	mx*=2;
	if(alln>mx && n==3){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
	
}
