#include <bits/stdc++.h>
using namespace std;
vector<int> last_app(pow(2,20) + 5, -1);
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin>>n>>k;
	vector<int> sum(n);
	vector<int> ip(n);
	int cur = 0;
	int ans = 0;
	int last_set_end = 0;
	for(int i = 0; i < n; i ++){
		int a;
		cin>>a;
		cur ^= a;
		int target = cur^k;
		if((last_app[target] != -1 and last_app[target] >= last_set_end ) or( target == 0 and last_set_end == 0)){
			last_set_end = i;
			ans++;
		}
		sum[i] = cur;
		last_app[cur] = i;
//		cout<<cur<<target;
	}
	cout<<ans;
	return 0;
}