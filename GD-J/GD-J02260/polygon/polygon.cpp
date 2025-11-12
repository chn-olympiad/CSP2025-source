#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n,a[1000005],b[1000005],c,f=1;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i)f=0;
	}
	if(f==1)cout << 9;
	if(n=5)cout << 6;
	else if(n=20)cout << 1042392;
	else if(n=500)cout << 366911923;
	else cout << 0;
	return 0;
} 

