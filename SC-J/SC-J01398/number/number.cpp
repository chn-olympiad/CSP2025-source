#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	short a[1000010];
	ll n=0;
	for(ll i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	n--;
	sort(a,a+n);
	for(ll i=0;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
