#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5,MAXM=5e6+5;
const int base=37;
const int mod=998244353;
string s[MAXN][3],t1,t2;
int h[MAXN][3];
int h1[MAXM],h2[MAXM];
int n,q,ans;
int pw[MAXM];
int Hash(string s){
	int res=0;
	int len=s.length();
	for(int i=0;i<len;i++){
		res=(res+s[i]*pw[len-i-1]%mod)%mod;
	}
	return res;
}
map<pair<string,string>,int> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		mp[{s[i][1],s[i][2]}]++;
	}
	while(q--){
		cin>>t1>>t2;
		int len=t1.length();
		int L=MAXM,R=-1;
		for(int i=0;i<len;i++){
			if(t1[i]!=t2[i]){
				L=min(L,i);
				R=max(R,i);
			}
		}
		ans=0;
		for(int l=0;l<=L;l++){
			for(int r=R;r<len;r++){
				string s1="",s2="";
				for(int i=l;i<=r;i++){
					s1+=t1[i];
					s2+=t2[i];
				}
				ans+=mp[{s1,s2}];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
//8pts?
//我的哈希炸了!可惜没复习好... 
