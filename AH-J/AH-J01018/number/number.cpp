#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[1000005];
ll cmp(const ll&x,const ll&y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll len=s.size(),pos=0;
	if(len==1){
		cout<<s[0];
		return 0;
	}
	for(ll i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') x[++pos]=s[i]-'0';
	}
	sort(x+1,x+1+pos,cmp);
	for(ll i=1;i<=pos;i++) cout<<x[i];
	return 0;
}
