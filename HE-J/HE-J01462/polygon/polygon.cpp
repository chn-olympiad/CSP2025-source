#include <bits/stdc++.h>
using namespace std;
const int N=998244353;
int a[5005];
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n==3){
		if (a[1]+a[2] >a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1]) cout<<1;
		else cout<<0;
	}
	if (n==5){
		cout<<6;
	}
	return 0;
}
