#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000005],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++top]=s[i]-'0';
		}
	}
	sort(a+1,a+top+1);
	for(ll i=top;i>=1;i--) cout<<a[i];
	return 0;
}

