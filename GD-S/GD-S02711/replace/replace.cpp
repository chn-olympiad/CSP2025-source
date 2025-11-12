#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll n,q;
struct node{
	string s1,s2;
}a[N];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			ll l=0;
			while(1){
				ll p=t1.find(a[i].s1,l);
				if(p==-1) break;
				string s=t1;
				if(s.replace(p,a[i].s1.size(),a[i].s2)==t2) cnt++;
				l=p+1;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
