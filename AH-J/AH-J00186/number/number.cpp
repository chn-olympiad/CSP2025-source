#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll f=0;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			f++;
			a[f]+=s[i];
		}
	}
	sort(a+1,a+f+1);
	for(ll i=s.size();i>=0;i--) cout<<a[i];
	return 0;
}
