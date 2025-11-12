#include <bits/stdc++.h>
using namespace std;
vector <int> ans;
string s;
bool cmp(int a,int b){return b>a;}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int sz=s.size();
	for(int i=0;i<sz;i++){
		if(isdigit(s[i])) ans.push_back(s[i]-'0');
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	for(auto it:ans) cout<<it;
	return 0;
}
