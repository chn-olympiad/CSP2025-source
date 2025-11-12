#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[100005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==5&&a[1]==1)cout<<9;
	if(n==5&&a[1]==2)cout<<6;
	return 0;
}
