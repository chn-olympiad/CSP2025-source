#include<bits/stdc++.h>
using namespace std;
string s;
vector<char> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a.push_back(s[i]);
	}
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--) cout<<int(a[i]-'0');
	return 0;
}

