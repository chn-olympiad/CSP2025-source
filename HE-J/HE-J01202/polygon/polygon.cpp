#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5010];
constexpr int mod=998244353;
bool f;
int ans;
int C(int x,int y){
	int res=1;
	for(int i=y+1;i<=x;i++) res*=i;
	for(int i=1;i<=(x-y);i++) res/=i; 
	return res%mod;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(n==3){
		sort(a+1,a+1+n);
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}else{
		for(int i=3;i<=n;i++) ans+=C(n,i);
		cout<<ans%mod;
	}
	return 0;
}
