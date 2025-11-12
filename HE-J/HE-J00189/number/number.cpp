#include<bits/stdc++.h>
using namespace std;
#define int int32_t
#define np nullptr
using ll = int64_t;
using str = string;
inline auto cmp(int a, int b) -> bool{
	return a > b;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(np);cout.tie(np);
	freopen("number.in", "r", stdin);
	freopen("number.out","w",stdout);
	str s, ans;
	cin>>s;
	int n = s.length();
	for(int i=0;i<n;i++)
		if(s[i] >= '0' && s[i] <= '9')
			ans += s[i];
	sort(ans.begin(), ans.end(), cmp);
	while(ans[1] == '0')
		ans.erase(ans.begin());
	cout<<ans<<"\n";
	return 0;
}
