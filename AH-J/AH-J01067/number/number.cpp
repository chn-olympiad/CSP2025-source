#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1;
	cin>>s;
	ll a=s.size();
	for(ll i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9') s1+=s[i];
	}
	sort(s1.begin(),s1.end());
	reverse(s1.begin(),s1.end());
	ll b=s1.size();
	for(int i=0;i<b;i++){
		cout<<s1[i];
	}

	return 0;
}
