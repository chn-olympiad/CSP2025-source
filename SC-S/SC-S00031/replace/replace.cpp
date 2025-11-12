#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
string s1,s2;
struct rplace{
	string sf,ss;
	string sft,sst; 
}a[100005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>a[i].sf>>a[i].ss;
		for(ll j=0;j<a[i].sf.size();j++){
			if(a[i].sf[j]!=a[i].ss[j]){
				a[i].sft+=a[i].sf[j];
				a[i].sst+=a[i].ss[j];
			}
		}
	}
	while(q--){
		cin>>s1>>s2;
		string sl1,sl2;
		ll ans=0;
		if(s1.size()==s2.size()){
			for(ll j=0;j<s1.size();j++){
				if(s1[j]!=s2[j]){
					sl1+=s1[j];
					sl2+=s2[j];
				}
			}
			for(ll i=1;i<=n;i++){
				if(sl1==a[i].sft&&sl2==a[i].sst){
					ans++;
				}
			}
		}else{
			ans=0;
		}
		cout<<ans;
		for(ll i=1;i<=n;i++){
			a[i].sf=a[i].sft=a[i].ss=a[i].sst='\0';
		}
	}
	return 0;
}