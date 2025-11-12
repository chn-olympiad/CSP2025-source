#include<bits/stdc++.h>
#define ll long long
#define N 1000010
using namespace std;
string s;
char a[N];
ll tot;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(ll i=0; i<s.size(); i++)
		if(s[i]<='9'&&s[i]>='0')
			a[++tot]=s[i];
	sort(a+1,a+tot+1);
	for(ll i=tot; i>=1; i--)
		cout<<a[i];
	return 0;
}