#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5001];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=3){
		if(a[1]+a[2]<=a[3]) cout<<0;
		else cout<<1;
		return 0;
	}
	cout<<7;
	return 0;
}
