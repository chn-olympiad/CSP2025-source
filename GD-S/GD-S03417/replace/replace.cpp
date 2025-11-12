#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s2[i]; 
	}
	while(q--){
		string t,t2;
		cin>>t>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			int x=t.find(s[i]),y=t2.find(s2[i]);
			if(x==-1||y==-1||x!=y) continue;
			string t3=t;
			t3.erase(x,s[i].size());
			t3.insert(x,s2[i]);
			if(t3==t2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
