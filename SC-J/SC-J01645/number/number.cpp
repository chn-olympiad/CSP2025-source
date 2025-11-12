#include<bits/stdc++.h>
using namespace std;
string t;
long long p[11];
long long con;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for (int i=0;i<t.length();i++) if (t[i]>='0'&&t[i]<='9') {
		p[t[i]-'0']++;
		con++;
	}
	if (con==p[0]) {
		cout<<0;
		return 0;
	}
	for (int i=9;i>=0;i--) 
		for (int j=1;j<=p[i];j++) cout<<i;
	return 0;
}