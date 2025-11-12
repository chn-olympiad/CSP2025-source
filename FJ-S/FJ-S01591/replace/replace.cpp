#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,q,ans,pos;
string s[N],st,tar;
map<string,string>mp;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i];cin>>mp[s[i]];
	}
	while(q--){
		cin>>st>>tar;
		ans=0;
		for(int i=1;i<=n;i++){
			string tmp=st;int sz=s[i].size();
			pos=tmp.find(s[i]);
			while(pos!=tmp.npos){
				string cur=tmp;
				if(cur.replace(pos,sz,mp[s[i]])==tar)
					ans++;
				tmp[pos]='~';
				pos=tmp.find(s[i]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
