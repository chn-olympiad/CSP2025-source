#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,string> ma;
ll n,q;
string lss;
string jq(string ss,ll l,ll r){
	if(l>r) return "";
	string re="";
	for(ll i=l;i<=r;i++) re+=ss[i];
	return re;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		ma[s1]=s2;
	}
	while(q--){
		string x,y;
		ll ans=0;
		cin>>x>>y;
		for(ll i=0;i<x.size();i++){
			for(ll j=0;j<=i;j++){
				string s1=jq(x,0,j-1);
				string s2=jq(x,j,i);
				string s3=jq(x,i+1,x.size()-1);
			
				lss="";
				lss+=s1;
				lss+=ma[s2];
				lss+=s3;
				if(lss==y&&s2.size()>0){
					//cout<<s1<<" "<<s2<<" "<<s3<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

