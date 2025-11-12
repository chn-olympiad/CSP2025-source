#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1;
vector<int> v;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1;
	for(int i=0;i<s1.size();i++)
		if(isdigit(s1[i])) v.push_back((s1[i]-'0'));
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++) cout<<v[i];
	return 0;
}