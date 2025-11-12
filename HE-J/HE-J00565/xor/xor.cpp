#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+1;
int n,k,a[N],s,len;
signed main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cout.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n>>k;
	for (int i = 1;i<=n;i++) cin>>a[i];
	for (int i = 1;i<=n;i++){
		s^=a[i];
		if (s==k){
			++len;
			s=0;
		}
	}
	cout<<len;
	return 0;
}
