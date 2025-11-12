//GZ-S00029 遵义市第十九中学 余学森 
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, q;
struct node {
	string s1,s2;
}s[N];

bool used[N];
int vec[N], tot, index,ans;

void dfs(string now,string&to) {
	if(now==to){
		ans++;
		return ;
	}
	for (int i = 0; i < tot; i++){
		if (used[i]) continue ;
		used[i]=1;
		string a = now.substr(0,vec[i]),b=now.substr(vec[i]+s[i].s1.size());
		dfs(a+s[i].s2+b,to);
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i = 1; i <= n; i++)
	    cin>>s[i].s1>>s[i].s2;
	while(q--){
		memset(used, 0, sizeof used);
		ans = 0;
		string t1,t2;
		cin>>t1>>t2;
		if (t1.size()!=t2.size()) {
			cout<<"0\n";
			continue ;
		}
		tot=0;
		for (int i = 1; i <= n; i++) {
			int pos = t1.find(s[i].s1);
			while (pos != string::npos) {
				vec[tot++]=pos;
				pos = t1.find(s[i].s1,pos+1);
			}
		}
		dfs(t1,t2);
		cout<<ans<<'\n';
	}
	return 0;
}
