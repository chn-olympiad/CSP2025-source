#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0; 
vector<int> ad;
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		int t; cin>>t;
		ad.push_back(t);
	}
	vector<int> c(n+1, 0);
	stack<vector<int> > ss;
	ss.push(c);
	while(!ss.empty()){
		vector<int> x = ss.top(); ss.pop();
		int t = x[x.size()-1];
		if(t>=3){
			int s = 0, m = 0;
			for(int i=0;i<n;++i){
				if(x[i] == 1){ // 选了
					s += ad[i]; m = max(ad[i], m);
				}
			}
			if (s > 2 * m) {
				ans++;
			}
		}
		// t 大于等于n，代表可能性全部测试完 
		if(t >= n) continue ;
		for(int i=n-1;i>=0;--i){ // 每一位点亮一个继续传
			if(x[i] == 0){ // 没有选
				vector<int> xs = x;
				xs[i] = 1;
				xs[x.size()-1] = t+1;
				ss.push(xs);
			}else break;
		} 
	}
	cout<<ans%9982443543;
	return 0;
}
