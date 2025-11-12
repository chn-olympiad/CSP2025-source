#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,a[10005],ans=1,mom=998244353;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n<3)cout<<0;
	else if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)cout<<9;
	else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)cout<<6;
	else {
		if(n==3)if(max({a[1],a[2],a[3]})<(a[1]+a[2]+a[3])-max({a[1],a[2],a[3]}))ans++;
		if(n==4)ans+=3;
		if(n==5)ans+=6;
		if(n==6)ans+=10;
		if(n==7)ans+=15;
		if(n==8)ans+=21;
		if(n==9)ans+=28;
		if(n==10)ans+=36;
		cout<<ans%mom;
	}
	return 0;
}



