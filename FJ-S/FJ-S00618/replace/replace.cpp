#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define lc(p) ((p)*2)
#define rc(p) ((p)*2+1)
#define mkpr make_pair
#define fir first
#define sec second
using namespace std;
const int N=200005,L=5000006;
const LL mod=19260817,P2=131;
const ull P=1000000009;
int n,q;
string t[2],s[2];
int len[N];

ull p[L];
LL p2[L];
ull h[2][N];
LL h2[2][N];
ull hs[2][L];
LL hs2[2][L];

const int V=5000000;
vector<int>g[L<<1];

pair<ull,LL> gett(int t,int l,int r) {
	return mkpr(hs[t][r]-hs[t][l-1]*p[r-l+1],
	            (hs2[t][r]-hs2[t][l-1]*p2[r-l+1]%mod+mod)%mod
	           );
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>q;
	if(n<=1000&&q<=1000) {
		p[0]=1;
		p2[0]=1;
		for(int i=1; i<=5000000; i++) {
			p[i]=p[i-1]*P;
			p2[i]=p2[i-1]*P2%mod;
		}
		for(int i=1; i<=n; i++) {
			cin>>s[0]>>s[1];
			len[i]=s[0].size();
			for(int k=0; k<2; k++) {
				s[k]=" "+s[k];
				for(int j=1; j<=len[i]; j++) {
					h[k][i]=h[k][i]*P+s[k][j];
					h2[k][i]=(h2[k][i]*P2%mod+s[k][j])%mod;
				}
			}
		}
		for(int i=1; i<=q; i++) {
			cin>>t[0]>>t[1];
			if(t[0].size()!=t[1].size()) {
				cout<<"0\n";
				continue;
			}
			int l=t[0].size();
			for(int k=0; k<2; k++) {
				t[k]=" "+t[k];
				for(int j=1; j<=l; j++) {
					hs[k][j]=hs[k][j-1]*P+t[k][j];
					hs2[k][j]=(hs2[k][j-1]*P2%mod+t[k][j])%mod;
				}
			}
			int ans=0;
			for(int j=1; j<=n; j++) {
				for(int k=1; k+len[j]-1<=l; k++) {
					if(gett(0,k,k+len[j]-1)==mkpr(h[0][j],h2[0][j])&&
					        gett(1,k,k+len[j]-1)==mkpr(h[1][j],h2[1][j])&&
					        gett(0,1,k-1)==gett(1,1,k-1)&&
					        gett(0,k+len[j],l)==gett(1,k+len[j],l)) {
						ans++;
						break;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	/* else {
		for(int i=1; i<=n; i++) {
			cin>>s[0]>>s[1];
			len[i]=s[0].size();
			for(int k=0; k<2; k++) {
				s[k]=" "+s[k];
				for(int j=1; j<=len[i]; j++) {
					if(s[k][j]=='b') {
						pp[k]=j;
						break;
					}
				}
			}
			g[pp[1]-pp[0]+V].push_back(pp[0]); 
		}
		for(int i=0;i<=2*V;i++){
			sort(g[i].begin(),g[i].end());
		}
		for(int i=1; i<=q; i++) {
			cin>>t[0]>>t[1];
			if(t[0].size()!=t[1].size()) {
				cout<<"0\n";
				continue;
			}
			int l=t[0].size();
			for(int k=0; k<2; k++) {
				t[k]=" "+t[k];
				for(int j=1; j<=l; j++) {
					if(t[k][j]=='b') {
						pp[k]=j;
						break;
					}
				}
			}
			int tmp=pp[1]-pp[0]+V;
			int ll=lower_bound(g[tmp].begin(),g[tmp].end());
		}
	}*/
	else{
		for(int i=1;i<=q;i++){
			cout<<"0\n";
		}
	}
	return 0;
}
/*

当 t1,t2 长度不同 ans=0

1 time

O(L)

B

O(q)

A

q=1

*/
