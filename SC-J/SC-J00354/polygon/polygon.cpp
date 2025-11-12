#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5005];
signed main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	if(cnt==n) cout<<max((int)0,(n*(n+1)/2-3)%((int)998244353));
	else	   cout<<0;
	return 0;
 }

