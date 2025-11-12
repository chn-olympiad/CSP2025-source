#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll sz[N],tot;
bool cmp(ll x,ll y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	ll siz=s.size();
	for(ll i=0;i<siz;i++){
		if(s[i]>='0'&&s[i]<='9') sz[++tot]=(s[i]-'0');
	}
	sort(sz+1,sz+tot+1,cmp);
	for(ll i=1;i<=tot;i++){
		putchar(sz[i]+'0');
	}
	return 0;
}