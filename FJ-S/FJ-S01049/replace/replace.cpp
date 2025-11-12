# include <bits/stdc++.h>
# define N 200010
using namespace std;
int n,q;
string s[N],ss[N];
map<string,int>mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	  cin>>s[i]>>ss[i],mp[s[i]]=i;
	string t,tt; int k;
	while(q--) {
	  cin>>t>>tt; int ans=0;
	  k=t.size(); string g="",ff="";
	  for(int i=0;i<k;i++) {
	    for(int j=i;j<k;j++) {
	      g="",ff="";
	      for(int l=0;l<i;l++) g+=t[l];
	      for(int l=i;l<=j;l++) ff+=t[l];
	      if(mp[ff]) g+=ss[mp[ff]];
	      else continue;
	      for(int l=j+1;l<k;l++) g+=t[l];
		  if(g==tt) ans++;
		}
	  }
	   cout<<ans<<"\n"; 
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb
