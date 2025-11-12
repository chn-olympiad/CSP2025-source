#include <bits/stdc++.h>
using namespace std;

int n,q,ans;
string w[200011][3],s1,s2;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin >> w[i][1] >> w[i][2]; 
	while (q--) {
		cin >> s1 >> s2;
		if (s1.size() != s2.size()) {
			puts("0");
			continue;
		}
		ans = 0;
		for(int i=1;i<=n;i++) {
			string str = w[i][1];
			if (s1.size() < str.size())
				continue;
			for(int j=0;j<=s1.size()-str.size();j++) {
				if (s1.substr(j,str.size()) == str) {
					string ns = s1.substr(0,j) + w[i][2] + s1.substr(j + str.size());
					if (ns == s2)
						ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
