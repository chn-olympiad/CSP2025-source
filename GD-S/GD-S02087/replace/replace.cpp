#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int mod=1e9+7,mod1=998244353,ba=130721,bb=780721;
int n,q,l[200005],r[200005],sz[200005],pw1[6000005],pw2[6000005],ib=1;
pair<int,int> h[6000005],sm[200005];
string s[200005][2];
vector<int> g[6000005];
pair<int,int> ht(int lx,int rx){
	return mp((h[rx].fi-h[lx-1].fi*pw1[rx-lx+1]%mod+mod)%mod,(h[rx].se-h[lx-1].se*pw2[rx-lx+1]%mod1+mod1)%mod1);
}
bool ic(string sr){
	int ct=0;
	for (int i=1;i<sr.size();i++){
		if (sr[i]!='a' && sr[i]!='b'){
			return 0;
		}else{
			ct+=(sr[i]=='b');
		}
	}
	return ct==1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	pw1[0]=pw2[0]=1;
	for (int i=1;i<=5e6;i++){
		pw1[i]=pw1[i-1]*ba%mod;
		pw2[i]=pw2[i-1]*bb%mod1;
	}
	for (int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		sz[i]=s[i][0].size();
		s[i][0]=" "+s[i][0];
		s[i][1]=" "+s[i][1];
		int ct1=0,ct2=0;
//		ib&=(ic(s[i][0],s[i][1]));
		for (int j=1;j<=sz[i];j++){
			if (s[i][0][j]!=s[i][1][j]){
				if (!l[i]){
					l[i]=j;
				}
				r[i]=j;
			}
//			cout<<i<<" "<<j<<endl;
		}
		if (l[i]){
			g[r[i]-l[i]].push_back(i);
		}
		for (int j=1;j<=sz[i];j++){
			sm[i]=mp((sm[i].fi*ba+s[i][0][j])%mod,(sm[i].se*bb+s[i][1][j])%mod1);
		}
	}
	while (q--){
		string t1,t2;
		int lt=0,rt=0,le,ans=0;
		cin>>t1>>t2;
		le=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		for (int i=1;i<=le;i++){
			if (t1[i]!=t2[i]){
				if (!lt){
					lt=i;
				}
				rt=i;
			}
			h[i]=mp((h[i-1].fi*ba+t1[i])%mod,(h[i-1].se*bb+t2[i])%mod1);
		}
		for (int i:g[rt-lt]){
			int st=lt-(l[i]-1);
////			cout<<lt<<" ";
			if (st<=0 || st+sz[i]-1>le){
				continue;
			}
			if (sm[i]==ht(st,st+sz[i]-1)){
				ans++;
//				gg.push_back(i);
			}
//			bool fl=1;
//			pair<int,int> dk;
//			for (int j=1;j<=sz[i];j++){
////				if (i+j-1>le)cout<<i+j-1<<" "<<le<<endl;
//				if (t1[st+j-1]!=s[i][0][j] || t2[st+j-1]!=s[i][1][j]){
//					fl=0;
//				}
//				dk=mp((dk.fi*ba+t1[st+j-1])%mod,(dk.se*bb+t2[st+j-1])%mod1);
//			}
//			if (fl){
////				cout<<sm[i].fi<<" "<<sm[i].se<<" "<<dk.fi<<" "<<" "<<(sm[sz[i]+st-1].fi-sm[st-1].fi*pw1[sz[i]-1]%mod+mod)%mod<<endl;
//			}
//			ans+=fl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
orz wj 
orz lxz
orz wsy
orz cyq
orz xza
*/
