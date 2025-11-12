#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005],t,st,to;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t;
		mp[s[i]]=t;
	}
	while(q--){
		cin>>st>>to;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int len=st.size(),len2=s[i].size();
			if(len<len2)continue;
			if(s[i]==st){
				if(mp[s[i]]==to)ans++;
			}else{
				int f=0;
				for(int j=0;j<len-len2+1;j++){
					string ss=st.substr(j,len2);
					string ts=to.substr(j,len2);
					if(ss==s[i] && ts==mp[s[i]])f++;
				}
				if(f==1)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
