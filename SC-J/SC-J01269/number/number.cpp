#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll num,a[1000006];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++num]=int(s[i]-'0');
	stable_sort(a+1,a+1+num);
	for(ll i=num;i>=1;i--) cout<<a[i];
	return 0;
} 