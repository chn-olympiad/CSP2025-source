#include<bits/stdc++.h>
#define x0 x_0
#define x1 x_1
#define y0 y_0
#define y1 y_1
#define yn y_n
#define j0 j_0
#define j1 j_1
#define jn j_n
#define k0 k_0
#define k1 k_1
#define d0 d_0
#define d1 d_1
#define LL long long
#define LD long double
#define Big __int128
#define STR string
#define US unsigned
#define ZPB push_back
#define ZPF push_front
#define PPB pop_back
#define PPF pop_front
#define next NXTNXT
#define UPB upper_bound
#define LWB lower_bound
#define mem(x,val) memset(x,val,sizeof(x))
using namespace std;
int n,q,L1,L2;
const int mod=998244353,base=19491001;
LL qp[2010];
STR s[1010][2],t[1010][2];
vector<LL> hs_s[1010][2],hs_t[1010][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q,qp[0]=1;
	for(int i=1;i<2010;++i) qp[i]=(qp[i-1]*base)%mod;
	for(int i=1;i<=n;++i) cin>>s[i][0]>>s[i][1],L1+=(int)s[i][0].size()+(int)s[i][1].size();
	for(int i=1;i<=q;++i) cin>>t[i][0]>>t[i][1],L2+=(int)t[i][0].size()+(int)t[i][1].size();
	if(n<=1000 && q<=1000 && L1<=2000 && L2<=2000){
		for(int i=1;i<=n;++i){
			hs_s[i][0].resize((int)s[i][0].size()+1),
			hs_s[i][1].resize((int)s[i][1].size()+1);
			for(int j=0;j<(int)s[i][0].size();++j) hs_s[i][0][j+1]=(hs_s[i][0][j]*base+s[i][0][j])%mod;
			for(int j=0;j<(int)s[i][1].size();++j) hs_s[i][1][j+1]=(hs_s[i][1][j]*base+s[i][1][j])%mod;
		}
		for(int i=1;i<=q;++i){
			if(t[i][0].size()^t[i][1].size()) {cout<<"0\n";continue;}
			hs_t[i][0].resize((int)t[i][0].size()+1),
			hs_t[i][1].resize((int)t[i][1].size()+1);
			for(int j=0;j<(int)t[i][0].size();++j) hs_t[i][0][j+1]=(hs_t[i][0][j]*base+t[i][0][j])%mod;
			for(int j=0;j<(int)t[i][1].size();++j) hs_t[i][1][j+1]=(hs_t[i][1][j]*base+t[i][1][j])%mod;
			int ans=0;
			for(int j=1;j<=n;++j){
				if(s[j][0].size()>t[i][0].size()) continue;
				int szs=(int)s[j][0].size();
				for(int p=0;p+szs-1<(int)t[i][0].size();++p){
//					cerr<<((hs_t[i][0][p+szs]-hs_t[i][0][p]*qp[szs])%mod+mod)%mod<<" "<<
					if(((hs_t[i][0][p+szs]-hs_t[i][0][p]*qp[szs])%mod+mod)%mod==hs_s[j][0].back() && 
					((hs_t[i][0].back()-(hs_t[i][0][p+szs]-hs_t[i][0][p]*qp[szs])%mod+hs_s[j][1].back()*qp[p])%mod+mod)%mod==
					hs_t[i][1].back()) ++ans;
				}
					
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

/*
input1:

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

output1:

2
0

*/
