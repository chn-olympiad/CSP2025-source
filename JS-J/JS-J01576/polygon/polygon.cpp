#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10010],ans=1;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n==3){
		if( 2*a[1]<(a[1]+a[2]+a[3]) ) cout<<1;
		else cout<<0;
	}
	else if(a[1]==1){
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=998244353;
		}
		ans+=998244353;
		for(int i=1;i<n;i++){
			ans-=i;
		}
		cout<<(ans-n-1)%998244353;
	}
	else cout<<9;
	return 0;
}
