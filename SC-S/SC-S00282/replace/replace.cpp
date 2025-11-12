#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+5,mod=(int)1e9+7,B=31;
int n,q,s1_hs[N],s2_hs[N],hhs[N],t2_hs,hhs2[N];
string s1[N],s2[N],t1[N],t2[N];
int POW[N]; 
void solve1(int i){	
	int ans=0;
	
	hhs[0]=0,t2_hs=0;
	for(int j=1;j<=t1[i].size();j++) hhs[j]=((hhs[j-1]*B+(t1[i][j-1]-'a'+1))%mod+mod)%mod;
	for(char c:t2[i]) t2_hs=((t2_hs*B+(c-'a'+1))%mod+mod)%mod;
	
	for(int op=1;op<=n;op++){
		int len1=t1[i].size(),len2=s1[op].size();
		for(int j=1;j+len2-1<=len1;j++){
			if(t1[i][j-1]!=s1[op][0]||t2[i][j-1]!=s2[op][0]) continue;
//			if(len2>=2&&(t1[i][j]!=s1[op][1]||t2[i][j]!=s2[op][1])) continue;
			
			int _l1=j-1,_l2=len2,_l3=len1-(j-1)-len2;
			int p1=hhs[_l1],p2=((hhs[_l1+_l2]-hhs[_l1]*POW[_l2])%mod+mod)%mod;
			int p3=((hhs[_l1+_l2+_l3]-hhs[_l1+_l2]*POW[_l3])%mod+mod)%mod;
			if(p2==s1_hs[op]&&((p1*POW[_l2+_l3]+s2_hs[op]*POW[_l3]+p3)%mod+mod)%mod==t2_hs){
				ans++;
				break;
			}
			if(t1[i][j-1]!=t2[i][j-1]) break;
		}
	}
	cout<<ans<<"\n";
}
unordered_map<int,int> mp;
void solve2(int i){
	hhs[0]=0,hhs2[0]=0;
	for(int j=1;j<=t1[i].size();j++){
		hhs[j]=((hhs[j-1]*B+(t1[i][j-1]-'a'+1))%mod+mod)%mod;
		hhs2[j]=((hhs2[j-1]*B+(t2[i][j-1]-'a'+1))%mod+mod)%mod;
	}
	
	int ans=0,len=t1[i].size();
	for(int l=1;l<=len;l++){
		for(int r=len;r>=l;r--){
			auto it=mp.find((hhs[r]-hhs[l-1]*POW[r-l+1]%mod+mod)%mod*mod+((hhs2[r]-hhs2[l-1]*POW[r-l+1])%mod+mod)%mod);
			if(it!=mp.end()) ans+=it->second;
			if(t1[i][r-1]!=t2[i][r-1]) break;
		}
		if(t1[i][l-1]!=t2[i][l-1]) break;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++) cin>>t1[i]>>t2[i];
	
	POW[0]=1;
	for(int i=1;i<=5e6+1;i++) POW[i]=POW[i-1]*B%mod;
	
	for(int i=1;i<=n;i++) for(char c:s1[i]) s1_hs[i]=(s1_hs[i]*B+(c-'a'+1))%mod;
	for(int i=1;i<=n;i++) for(char c:s2[i]) s2_hs[i]=(s2_hs[i]*B+(c-'a'+1))%mod;
	
	int sumL=0;
	for(int i=1;i<=q;i++) if(t1[i].size()==t2[i].size()) sumL+=t1[i].size();
	
	for(int i=1;i<=n;i++) mp[s1_hs[i]*mod+s2_hs[i]]++;
	for(int i=1;i<=q;i++){
		if(t1[i].size()!=t2[i].size()) cout<<0<<"\n";
		else if(t1[i].size()>sqrt(sumL*10)) solve1(i);
		else solve2(i);
//		else solve1(i);
	}
	return 0;
}
/*
似乎看出了疑似正解的东西？
根号分治的话也许能做
大串直接暴力，小串换另一种方式暴力似乎就可以了

不对，这数据范围是根号所过不去的

1 1
xabcx xadex
xabcx xadex

1 1
a b
a b
*/