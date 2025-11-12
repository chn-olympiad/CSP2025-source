#include <bits/stdc++.h>
//#define int long long
#define debug(x) cout<<#x<<" = "<<x<<' '
#define N 10010
#define ull unsigned long long
#define base 233
using namespace std;

int n,q,sz;
ull ha[N],hs[N];
string s[N][3];

ull Hash(string s){
	int x=(s[0] == ' ');
	ull Pow=1,ans=0;
	for(int i=x;i<n+x;i++){
		ans+=(s[i]-'a')*Pow;
		Pow*=base;
	}
	return ans;
}

void init(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		s[i][1]=' '+s[i][1],s[i][2]=' '+s[i][2];
		ha[i]=Hash(s[i][1]),hs[i]=Hash(s[i][2]);
//		debug(i),debug(ha[i]),debug(hs[i])<<endl;
	}
}

void solve(){
	while(q--){
		string t1,t2;
		cin>>t1>>t2,sz=t1.size();
		t1=' '+t1,t2=' '+t2;
		
		int l=1,r=sz,ans=0;
		while(t1[l] == t2[l] && l <= sz) l++;
		while(t1[r] == t2[r] && r >= 1) r--;
//		debug(l),debug(r)<<endl;
		
		for(int i=1;i<=l;i++){
			for(int j=r;j<=sz;j++){
				string tmp=t1.substr(i,j-i+1),ttp=t2.substr(i,j-i+1);
//				debug(tmp),debug(ttp)<<endl;
				ull has=Hash(tmp),hss=Hash(ttp);
//				debug(has),debug(hss)<<endl;
				
				for(int k=1;k<=n;k++)
					if(has == ha[k] && hss == hs[k])
						ans++;
			}
		}
		
		cout<<ans<<endl;
	}
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int T=1;
	while(T--){
		init();
		solve();
	}
	return 0;
}

