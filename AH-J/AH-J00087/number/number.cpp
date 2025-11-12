#include <bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s,t="";
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if('0'<=s[i]&&s[i]<='9'){
			t+=s[i];
		}
	}
	sort(t.begin(),t.end(),cmp);
	cout<<t;
	return 0;
}
