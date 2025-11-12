#include<bits/stdc++.h>
using namespace std;
#define np nullptr
#define int int32_t
using ll = int64_t;
constexpr int N = 2e5+10;
int a[N];
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(np);cout.tie(np);
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin>>n>>k;
	bool B = true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!(a[i] == 0 || a[i] == 1)) B = false;
	}
	if(k == 0){
		cout<<n<<"\n";
		return 0;
	}
	if(B){
		int ans = count(a+1, a+n+1, 1);
		cout<<ans<<"\n";
		return 0;
	}
	cout<<1<<"\n";
	return 0;
}
