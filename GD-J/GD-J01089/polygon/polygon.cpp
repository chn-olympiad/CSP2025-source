#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	if(n==1 || n==2) cout << 0 << endl;
	else if(n==3){
		if(a[3]>=a[1]+a[2]) cout << 0;
		else cout << 1;
	} else {
		int t=n-2,ans=0;
		for(int i=1;i<=t;i++) ans=(ans+i*i)%998244353;
		cout << ans;
	}
	return 0;
}
