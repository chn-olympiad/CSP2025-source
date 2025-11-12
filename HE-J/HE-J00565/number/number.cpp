#include <bits/stdc++.h>
#define int long long
using namespace std;
inline bool cmp(char a,char b){
	return a>b;
}
signed main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cout.tie(nullptr)->ios::sync_with_stdio(false);
	string s,str="";
	cin>>s;
	for (size_t i = 0;i<s.size();i++) if (isdigit(s[i])) str+=s[i];
	sort(str.begin(),str.end(),cmp);
	cout<<str;
	return 0;
}
