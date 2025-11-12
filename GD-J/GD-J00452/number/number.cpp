#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
vector<ll> n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>=48&&s[i]<=57)
			n.push_back(s[i]-48);
	sort(n.begin(),n.end(),greater<ll>());
	for(int i=0;i<n.size();i++)
		cout<<n[i];
	return 0;
}
