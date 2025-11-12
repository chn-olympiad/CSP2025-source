#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll num[N],len;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll n=s.size();
	for(ll i=0;i<n;i++) if(isdigit(s[i])) num[++len]=s[i]-'0';
	sort(num+1,num+len+1);
	for(ll i=len;i>=1;i--) cout<<num[i];
	return 0;
}
