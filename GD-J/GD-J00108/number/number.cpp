#include<bits/stdc++.h>
using namespace std;
string s;
int l;
map<int,int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++) {
		if(s[i]<='9'&&s[i]>='0') 
			m[int(s[i]-'0')]++;
	}
	for(int i=9;i>=0;i--) {
		for(int j=1;j<=m[i];j++) 
			cout<<i;
	}
	
	return 0;
}
