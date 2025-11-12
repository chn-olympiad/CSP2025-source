#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=(int)b;i++)
#define ROF(i,a,b) for(int i=b;i>=(int)a;i--)
const int N=1e6+10;
const ll inf=1e9+10;
const ll mod=1e9+7;
using Vl=vector<ll>;
using PI=array<ll,2>;
using PS=array<string,2>;
ll n,q;
string s,t;
PS lim[N];
bool pf=1;
map<string,string> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>q;
	FOR(i,1,n){
		cin>>lim[i][0]>>lim[i][1];mp[lim[i][0]]=lim[i][1];
		for(char ch:lim[i][0]) if(ch!='a'&&ch!='b') pf=0;
		for(char ch:lim[i][1]) if(ch!='a'&&ch!='b') pf=0;
	}
	if(pf){
		while(q--){
			cin>>s>>t;ll l,r,ans=0;
			for(int i=0;i<s.size();i++) if(s[i]=='b'){l=i;break;}
			for(int i=0;i<t.size();i++) if(t[i]=='b'){r=i;break;}
			FOR(i,1,n){
				int it=lim[i][0].find('b'),it1=lim[i][1].find('b');
				if(it1-it==r-l&&it<=l&&it1<=r&&l-it+lim[i][0].size()<=s.size()) ans++;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(q--){
		cin>>s>>t;int l,r,ans=0;
		for(int i=0;i<s.size();i++) if(s[i]!=t[i]){l=i-1;break;}
		for(int i=s.size()-1;i>=0;i--) if(s[i]!=t[i]){r=i+1;break;}
		if(l==-1&&r==s.size()) cout<<(mp.count(s)?mp[s]==t:0)<<'\n';
		l++,r--;
		FOR(i,1,n){
			if(lim[i][0].size()<r-l+1) continue;
			string u=lim[i][0],v=lim[i][1];
			int L=max(0,(int)(r-u.size()+1));
			while(L<=l){
				int it=s.find(u,L);
				if(it==-1||it>l) break;
				if(t.substr(it,u.size())==v){ans++;break;}
				L=it+1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
