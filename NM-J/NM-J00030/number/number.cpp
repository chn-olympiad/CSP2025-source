#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int N=1e7+10;
int a[N];
int main() {

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	ll cnt=0;
	cin>>s;
	ll suckdick=s.length();
	for(ll i=0; i<suckdick; i++) {
		if(s[i]<='9'&&s[i]>='0') {
			cnt++;
			a[cnt]=s[i]-48;
		}
	
	}
	sort(a+1,a+cnt+1);
	for(ll i=cnt; i>=1;i--) {
		cout<<a[i];
	}
	return 0;
}
