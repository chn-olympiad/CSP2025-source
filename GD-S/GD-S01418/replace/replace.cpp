#include<bits/stdc++.h>
#define psb push_back
#define fi first
#define se second
#define endl '\n'
#define SZ(a) ((int)a.size())
using namespace std;
using ll=long long;
const int N=2e5+5,mod=1e9+7,P=131;
int n,q;
string s1[N],s2[N],t1[N],t2[N];
unordered_map<ll,int> mp;
void solve1(){
	for(int i=1;i<=n;i++){
		int len=SZ(s1[i]),hs1=0,hs2=0;
		for(int j=0;j<len;j++){
			hs1=(1ll*hs1*P+s1[i][j])%mod;
			hs2=(1ll*hs2*P+s2[i][j])%mod;
		}
		mp[1ll*hs1*mod+hs2]++;
	}
	for(int i=1;i<=q;i++){
		int len=SZ(t1[i]);
		if(SZ(t2[i])!=len){cout<<0<<endl;continue;}
		len--;
		int x=0,y=len+1;
		while(x<len&&t1[i][x+1]==t2[i][x+1])x++;
		while(y>=2&&t1[i][y-1]==t2[i][y-1])y--;
		int ans=0;
		for(int j=1;j<=min(x+1,len);j++){
			int hs1=0,hs2=0;
			for(int k=j;k<=len;k++){
				hs1=(1ll*hs1*P+t1[i][k])%mod;
				hs2=(1ll*hs2*P+t2[i][k])%mod;
				if(k>=y-1)ans+=mp[1ll*hs1*mod+hs2];
			}
		}
		cout<<ans<<endl;
	}
}
void solve2(){
//	for(int i=1;i<=q;i++){
//		
//	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	int l1=0,l2=0;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i]; 
		l1+=SZ(s1[i])<<1;
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		l2+=SZ(t1[i])+SZ(t2[i]);
		t1[i]=" "+t1[i],t2[i]=" "+t2[i];
	}
	solve1();
//	if(l1<=2000&&l2<=2000)solve1();
//	else solve2();
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
