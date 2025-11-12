#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[114514];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<n-2;
	return 0;
}
