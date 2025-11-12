#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+10;
string s;
ll dict[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.size();
	for(ll i=0;i<len;++i){
		if(s[i]>='0'&&s[i]<='9') dict[s[i]-48]++;
	}
	for(ll i=9;i>=0;--i){
		if(dict[i]!=0){
			ll k=dict[i];
			while(k--){
				cout<<i;
			}
		}
	}
	return 0;
}