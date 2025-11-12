#include <bits/stdc++.h>
#define MAXN 200011
using namespace std;
int n,q;
pair<string,string>s[MAXN],t;
int sl;
struct node{
	int fr,ls;
};
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++) {
		cin >> s[i].first >> s[i].second;
		sl+=s[i].first.size()+s[i].second.size();
	}
	while(q--) {
		cin >> t.first >> t.second;
		if (t.first.size()!=t.second.size()) {
			cout << 0 << endl;
			continue;
		}
		int len=t.first.size();
		string dif1="",dif2="";
		int flag=0;
		for (int i=0;i<len;i++) {
			if (t.first[i]!=t.second[i]) {
				if (flag==2) {
					flag=3;
					break;
				}
				dif1+=t.first[i],dif2+=t.second[i];
				if (!flag) flag=1;
			}
			else if (flag==1) flag=2;
		}
		if (flag==3){
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for (int i=1;i<=n;i++) {
			if (s[i].first.find(dif1)!=string::npos&&s[i].second.find(dif2)!=string::npos){
				if (t.first.find(s[i].first)!=string::npos&&t.second.find(s[i].second)!=string::npos) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
