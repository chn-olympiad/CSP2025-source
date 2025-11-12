#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0,nl=1,cs=2;
int a[5100];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		nl*=i;
	}
	for(int i=3;i<=n;i++){
		cs*=i;
		nl/=cs;
		ans+=nl;
	}
	cout<<ans%998%244%353<<endl;
	return 0;
}

