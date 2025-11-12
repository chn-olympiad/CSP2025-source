#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,string> pss;
const int N = 5e5 + 31;

map<pss,int> mp;
int n,q;
string s,t;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++){
		cin >> s >> t;
		mp[pss(s,t)]++;
	}
	while(q--){
		cin >> s >> t;
		string a,b;
		int len = s.size(),id = 0;
		for(int i = len - 1;i >= 0;i--)
			if(s[i] != t[i]){
				id = i;
				break;
			}
		ll ans = 0;
		for(int i = 0;i < len;i++){
			a.clear(), b.clear();
			for(int j = i;j < id;j++)
				a.push_back(s[j]), b.push_back(t[j]);
			for(int j = id;j < len;j++){
				a.push_back(s[j]), b.push_back(t[j]);
				ans += mp[pss(a,b)];
			}
			if(s[i] != t[i])
				break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
