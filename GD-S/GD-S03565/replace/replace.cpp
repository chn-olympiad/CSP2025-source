#include <bits/stdc++.h>
using namespace std;

map<string ,set<string> >w;
int n,q;
string ns,nt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s,t;
		cin >> s >> t;
		w[s].insert(t);
	}
	while(q--){
		string s,t;
		cin >> s >> t;
		int l=0,r=0;
		for(int i=0;i<s.length();i++){
			if(s[i]!=t[i]){
				l=i;
				break;
			}
		}
		for(int i=s.length()-1;i;i--){
			if(s[i]!=t[i]){
				r=i;
				break;
			}
		}
		int ans=0;
		for(int i=0;i<=l;i++){
			string u=s.substr(i,r-i),v=t.substr(i,r-i);
			for(int j=r;j<s.length();j++){
				u=u+s[j],v=v+t[j];
				if(w[u].find(v)!=w[u].end()) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0; 
}
