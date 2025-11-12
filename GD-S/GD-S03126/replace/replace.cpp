#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int base=1331;
const int N=1e3+10;
const int M=2e3+10;
int n,q;
string s[N][2];
int len[N][2];
int hsh[N][2][M];
int hs[2][M],pw[M];
inline void init_() {
	pw[0]=1;
	for(int i=1;i<M;i++)
		pw[i]=pw[i-1]*base%mod;
	return ;
}
inline int gethsh(int l,int r,int *has) {
	return (has[r]-has[l-1]*pw[r-l+1]%mod+mod)%mod;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	init_();
	for(int i=1;i<=n;i++) {
		cin>>s[i][1]>>s[i][2];
		len[i][1]=s[i][1].size();
		len[i][2]=s[i][2].size();
		s[i][1]=' '+s[i][1];
		s[i][2]=' '+s[i][2];
		for(int j=1;j<=len[i][1];j++)
			hsh[i][1][j]=(hsh[i][1][j-1]*base%mod+(s[i][1][j]-'a'))%mod;
		for(int j=1;j<=len[i][2];j++)
			hsh[i][2][j]=(hsh[i][2][j-1]*base%mod+(s[i][2][j]-'a'))%mod;
	}
	while(q--) {
		string t1,t2;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		t1=' '+t1,t2=' '+t2;
		for(int i=1;i<=l1;i++)
			hs[1][i]=(hs[1][i-1]*base%mod+(t1[i]-'a'))%mod;
		for(int i=1;i<=l2;i++)
			hs[2][i]=(hs[2][i-1]*base%mod+(t2[i]-'a'))%mod;
		int ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=l1;j++) {
				if(j+len[i][1]-1<=l1) {
					bool flag=1;
					if(gethsh(1,len[i][1],hsh[i][1])==gethsh(j,j+len[i][1]-1,hs[1])) {
						if(j>1) {
							if(gethsh(1,j-1,hs[1])!=gethsh(1,j-1,hs[2]))
								flag=0;
						}
						if(j+len[i][1]-1<l1) {
							if(gethsh(j+len[i][1],l1,hs[1])!=gethsh(j+len[i][1],l1,hs[2]))
								flag=0;
						}
						if(gethsh(1,len[i][2],hsh[i][2])!=gethsh(j,j+len[i][1]-1,hs[2]))
							flag=0;
						if(flag) ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
