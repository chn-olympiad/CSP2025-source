#include <bits/stdc++.h>
using namespace std;
string sa,sb;
int n,q,ans=0;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sa>>sb;
		mp[sa]=sb;
	}
	if(1){
		while(q--){
			ans=0;
			cin>>sa>>sb;
			int idx=sa.find('b');
			for(auto it=mp.begin();it!=mp.end();it++){
				string t,to;
				t=it->first;
				to=it->second;
				int iax=t.find('b');
				int ibx=to.find('b');
				if(idx<iax){
					continue;
				}
				int c=ibx-iax;
				swap(sa[idx],sa[idx+c]);
				if(sb[idx+c]=='b'){
					ans+=1;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	while(q--){
		ans=0;
		cin>>sa>>sb;
		for(auto it=mp.begin();it!=mp.end();it++){
			string t,to;
			t=it->first;
			to=it->second;
			//cout<<t<<endl;
			for(int l=0;l+t.size()-1<sa.size();l++){
				string s=sa.substr(l,t.size());
			//	cout<<s<<endl;
				if(s!=t){
					continue;
				}
				string tmp=sa;
			
				for(int i=0;i<t.size();i++){
					tmp[l+i]=to[i];
				}
			//	cout<<tmp<<endl;
				if(tmp==sb){
					ans+=1;
				}
			}
		}
		cout<<ans<<endl;
	}
}
