#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2],t1,t2;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		mp[s[i][0]]=s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0<<"\n";
			continue;
		}
		int l1=t1.length();
		t1="#"+t1;
		t2="#"+t2;
		long long ans=0;
		for(int l=1;l<=l1;l++){
			for(int r=l;r<=l1;r++){
				string q1=t1.substr(1,l-1),q2=t2.substr(1,l-1);
				if(q1!=q2) continue;
				string ho1=t1.substr(r+1),ho2=t2.substr(r+1);
				if(ho1!=ho2) continue;
				string h1=t1.substr(l,r-l+1);
				string h2=t2.substr(l,r-l+1);
				if(mp.find(h1)!=mp.end()){
					if(mp[h1]==h2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
