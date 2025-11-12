#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
string s;
int t[15];
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0' and s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for (int i=9;i>=1;i--){
		for (int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	for (int i=1;i<=t[0];i++) cout<<0;
	return 0;
}

// Hi,CSP-J.
