#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int>
#define A3 array<int,3>
using namespace std;
const int N = 1e6 + 10,mod = 1e9 + 7,base = 131,inf = 1e18;
int n,m;
string s1[N],s2[N];
unordered_map<string,int> mp;
unordered_map<int,int> cnt[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	int idx=0;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		//s1[i]=" "+s1[i],s2[i]=" "+s2[i];
		if(mp[s1[i]]==0) mp[s1[i]]=++idx;
		if(mp[s2[i]]==0) mp[s2[i]]=++idx;
		cnt[mp[s1[i]]][mp[s2[i]]]++;
		cnt[mp[s2[i]]][mp[s1[i]]]++;
	}
	for(int i=1;i<=m;i++){
		string s,t; cin>>s>>t;
		int len=s.size(),ans=0;
		s=" "+s,t=" "+t; 
		for(int l=1;l<=len;l++){
			if(s[l-1]!=t[l-1]) break;
			for(int r=len;r>l;r--){
				if(s[r+1]!=t[r+1]) break;
				string p1=s.substr(l,r-l+1);
				string p2=t.substr(l,r-l+1);
		        if(mp[p1]==0) mp[p1]=++idx;
		        if(mp[p2]==0) mp[p2]=++idx;
				ans+=cnt[mp[p1]][mp[p2]];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/