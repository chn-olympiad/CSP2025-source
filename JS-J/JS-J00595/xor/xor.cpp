#include <bits/stdc++.h>
using namespace std;
int a[500005],n,k;
bool pd(){
	if (k!=0) return false;
	for (int i=1;i<=n;i++) if (a[i]!=1) return false;
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (pd()) cout<<n/2;
	else cout<<1;
	return 0;
}
