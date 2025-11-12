#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
pair<string,string> s[200005];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].first>>s[i].second;
	while(q--){
		ans=0;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<s1.size();j++){
				if(s1.substr(j,s[i].first.size())==s[i].first){
					string s3=s1;
					s3.erase(j,s[i].first.size());
					s3.insert(j,s[i].second);
					if(s3==s2) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

