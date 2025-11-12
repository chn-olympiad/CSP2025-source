#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;vector<int>v;
bool cmp(int x,int y){return x>y;}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;for(int i=0;i<(int)s.size();i++)if('0'<=s[i]&&s[i]<='9')v.push_back(s[i]-'0');
	sort(v.begin(),v.end(),cmp);
	for(auto& it:v){
		cout<<it;
	}
	return 0;
}