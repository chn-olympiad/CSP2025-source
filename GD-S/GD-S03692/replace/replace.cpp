#include <bits/stdc++.h>
using namespace std; 

const int kMaxN = 1e6+2;
int n,q;
string from[101],to[101],q1[101],q2[101];
int dp[201][101];

bool check(string& a,string& b,string& from,string& to,int L,int len) {
	for (int i=0;i<len;i++) {
		if (a[L+i]==from[i]&&b[L+i]==to[i]) {
			return true;
		}
	}
	return false;
}

signed main(void) {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for (int i=1;i<=n;i++) {
		cin >> from[i] >> to[i];
	}
	for (int i=1;i<=q;i++) {
		cin >> q1[i] >> q2[i];
	}
	for (int i=1;i<=q;i++) {
		int ans{0};
		for (size_t split=0;split<q1[i].size();split++) {
			for (int j=1;j<=n;j++) {
				int len = from[j].size();
				if (check(q1[i],q2[i],from[j],to[j],split,len)) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

