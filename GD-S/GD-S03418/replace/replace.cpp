#include<bits/stdc++.h>
using namespace std;
#define pss pair<string,string>
#define fi first
#define sc second
const int N = 2e5+10;
int n,t;
map<pss,vector<pss>> mp;

bool chk(pss x,pss y){ //y与x：y.fi 是 x.fi 的后缀，y.sc 是 x.sc 的前缀 
	if(y.fi.size()>x.fi.size() || y.sc.size()>x.sc.size()) return false;
	int len1,len2;
	len1 = x.fi.size(),len2 = y.fi.size();
	for(int i=1;i<=len2;i++){
		if(x.fi[len1-i]!=y.fi[len2-i])
			return false;
	}
	len1 = x.sc.size(),len2 = y.sc.size();
	for(int i=0;i<len2;i++){
		if(x.sc[i]!=y.sc[i])
			return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>t;
	while(n--){
		string s1,s2;
		pss p,q; //p为共同外段 q为差异段 
		cin>>s1>>s2;
		if(s1==s2) continue;
		int len = s1.size();
		for(int i=0;i<len;i++){
			if(s1[i]!=s2[i]){
				p.fi = s1.substr(0,i);
				for(int j=len-1;j>=0;j--){
					if(s1[j]!=s2[j]){
						q.fi = s1.substr(i,j-i+1);
						q.sc = s2.substr(i,j-i+1);
						p.sc = s1.substr(j+1,len-j);
						break;
					}
				}
				break;
			}
		}
		mp[q].push_back(p);
	}
	while(t--){
		int ans = 0;
		string t1,t2;
		pss p,q;
		cin>>t1>>t2;
		int len = t1.size();
		for(int i=0;i<len;i++){
			if(t1[i]!=t2[i]){
				p.fi = t1.substr(0,i);
				for(int j=len-1;j>=0;j--){
					if(t1[j]!=t2[j]){
						q.fi = t1.substr(i,j-i+1);
						q.sc = t2.substr(i,j-i+1);
						p.sc = t1.substr(j+1,len-j);
						break;
					}
				}
				break;
			}
		}
		for(auto x:mp[q])
			ans+=chk(p,x);
		cout<<ans<<"\n";
	}
	return 0;
}
