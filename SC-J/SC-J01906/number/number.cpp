#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long ll;
string s;
ll num[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll lens = s.size();
	ll m = 0;
	for(ll i = 0;i<lens;++i){
		if(isdigit(s[i])){
			num[++m] = s[i]-'0'; 
		}
	}
	sort(num+1,num+m+1);
	for(ll i = m;i>=1;--i){
		cout<<num[i];
	}
	return 0;
}