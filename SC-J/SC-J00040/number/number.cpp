#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000000+10],len=0;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++) if(s[i]>='0' && s[i]<='9') a[++len]=s[i]-'0';
	sort(a+1,a+len+1,cmp);
	for(ll i=1;i<=len;i++) cout<<a[i];
	return 0;
}