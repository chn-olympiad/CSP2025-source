#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,s2;
const int N=1e6+10;
ll a[N],c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') s2+=s[i];
	}
//	for(int i=0;i<s2.size();i++){
//		cout<<s2[i];
//	}
	for(ll i=0;i<s2.size();i++){
		a[i]=s2[i]-'0';
//		cout<<a[i];
	}
	sort(a,a+s2.size(),greater<int>());
	for(ll i=0;i<s2.size();i++){
		cout<<a[i];
	}
	return 0;
} 