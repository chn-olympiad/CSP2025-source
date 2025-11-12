#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
int n,q;
pair<string,string>s[200005],t[200005];
string sg[200005];
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	file("replace")
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	for(int i=1;i<=q;i++){
		cin>>t[i].first>>t[i].second;
		if(t[i].first.size()!=t[i].second.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			if(t[i].first.find(s[j].first)==-1){
				continue;
			}
			if(t[i].second.find(s[j].second)==-1){
				continue;
			}
			if(t[i].first.find(s[j].first)!=t[i].second.find(s[j].second)){
				continue;
			}
			int l=t[i].first.find(s[j].first)-1;
			int r=l+s[j].first.size();
			bool jia=1;
			for(int k=0;k<=l;k++){
				if(t[i].first[k]!=t[i].second[k]){
					jia=0;
					break;
				}
			}
			if(jia){
				int tlen=t[i].first.size()-1;
				for(int k=r+1;k<=tlen;k++){
					if(t[i].first[k]!=t[i].second[k]){
						jia=0;
						break;
					}
				}
			}
			if(jia)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

