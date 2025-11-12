#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	string s;cin>>s;
	int n=s.length();
	vector<int> V;
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			V.pb(s[i]-'0');
		}
	}
	sort(V.begin(),V.end());
	int sz=V.size();
	for(int i=sz-1;i>=0;i--) cout<<V[i];
	cout<<'\n';
	return 0;
}
