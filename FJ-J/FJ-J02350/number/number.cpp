#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N=1e6+100;
string s;
int t=1,a[N];
signed main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9') a[t++]=s[i]-'0';
	}
	t--;
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--) cout<<a[i];
	return 0;
}
/*
290es1q0
5
*/
