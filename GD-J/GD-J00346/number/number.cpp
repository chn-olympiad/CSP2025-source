#include <bits/stdc++.h>
using namespace std;

string s;
vector<short> cur;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') cur.push_back(s[i]-'0');
	}
	sort(cur.begin(),cur.end());
	for(int i=cur.size()-1;i>=0;i--){
		cout<<cur[i];
	}
	return 0;
}
