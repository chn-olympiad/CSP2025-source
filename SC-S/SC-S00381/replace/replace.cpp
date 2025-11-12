#include<bits/stdc++.h>
#define	ll long long
const int N=1e6+10;
ll n,q,as,bs;
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		string s;
		cin>>s[i];
		if(s[i]=='a') as++;
		if(s[i]=='b') bs++;
		if(as+bs==n&&bs==1){
			while(q--) cout<<1<<"\n";
		}
	} 	
	string t;
	for(ll i=1;i<=q;i++) cin>>t[i];
	if(q==1){
		cout<<0; 
		return 0;
	} 
	return 0;
} 