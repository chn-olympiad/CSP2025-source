/*by lz*//*ccf明年出简单一点吧*//*25*/
#include<bits/stdc++.h>
using namespace std;
const int NN=1e5+5;
string s1,s2;
int n,q;
struct node {
	string a,b;
} some[NN];
pair<int,int> b_cnt[NN][2];
pair<int,int> findb(string s) {
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='b') {
			return {i,s.size()-i-1};
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>some[i].a>>some[i].b;
		b_cnt[i][0]= {findb(some[i].a)};
		b_cnt[i][1]= {findb(some[i].b)};
	}
	for(int i=1; i<=q; i++) {
		int ans=0;
		cin>>s1>>s2;
		int before_b_s1=findb(s1).first;
		int before_b_s2=findb(s2).second;
		int after_b_s1=findb(s1).first;
		int after_b_s2=findb(s2).second;
		for(int j=1; j<=n; j++) {
			int before_b_some_s1=b_cnt[i][0].first;
			int before_b_some_s2=b_cnt[i][0].second;
			int after_b_some_s1=b_cnt[i][1].first;
			int after_b_some_s2=b_cnt[i][1].second;
			if(before_b_s1>=before_b_some_s1
			        &&before_b_s2>=before_b_some_s2
			        &&after_b_s1>=after_b_some_s1
			        &&after_b_s2>=after_b_some_s2) {
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}

