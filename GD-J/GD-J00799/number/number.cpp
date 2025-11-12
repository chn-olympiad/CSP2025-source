#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s; cin>>s;
	for(int i=0,len=s.size();i<len;i++)
		if('0'<=s[i] and s[i]<='9')
			a.push_back((int)(s[i]-'0'));
	sort(a.begin(),a.end());
	string ans;
	for(int i=a.size()-1;i>=0;i--) ans+=(a[i]+'0');
	cout<<ans<<"\n"; 
	return 0;
}
