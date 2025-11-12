#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+6;
ll n[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll k=0;
	for(ll i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			n[++k]=s[i]-'0';
	sort(n+1,n+1+k);
	for(int i=k;i>=1;i--)
		cout<<n[i];
	return 0;
}