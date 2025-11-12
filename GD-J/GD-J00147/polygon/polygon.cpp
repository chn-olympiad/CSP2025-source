#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(s,"r",stdin)
#define out(s) freopen(s,"w",stdout)
typedef long long ll;
const int mod = 998244353;

int n;
int arr[5005],tep[5005];
map<int,ll> se[5005];
ll ans;

int main(){
	in("polygon.in");
	out("polygon.out");
	se[0][0] = 1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr+1,arr+n+1);
	if (arr[n] == 1){
		ll a[5005] = {1};
		for(int i=1;i<=n;i++){
			a[i] = a[i-1]<<1;
			a[i] %= mod;
		}
		ll b[5005] = {};
		for(int i=1;i<=n;i++){
			b[i] = b[i-1]+a[i-1];
			b[i] %= mod;
		}
		ll c[5005] = {};
		for(int i=1;i<=n;i++){
			c[i] = c[i-1]+b[i-1];
			c[i] %= mod;
		}
		ll d[5005] = {};
		for(int i=1;i<=n;i++){
			d[i] = d[i-1]+c[i-1];
			d[i] %= mod;
		}
		printf("%lld",d[n]);
		return 0;
	}
	for(int i=1;i<=n;i++){
		tep[i] = arr[i]<<1;
		for(auto j:se[i-1]){
			se[i][j.first] += j.second;
			se[i][j.first] %= mod;
			se[i][j.first+arr[i]] += j.second;
			se[i][j.first+arr[i]] %= mod; 
			if (j.first+arr[i] > tep[i]){
				ans += se[i][j.first+arr[i]];
				ans %= mod; 
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
/*

3
1 1 1
1


4
1 1 1 1
5

5
1 1 1 1 1
16

6
1 1 1 1 1 1
42

7
1 1 1 1 1 1 1
99

8
1 1 1 1 1 1 1 1
219
*/ 
