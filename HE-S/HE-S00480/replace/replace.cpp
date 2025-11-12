#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,M=5e6+5,B=29,MOD=998244353377;
int n,m,ans;
int p[M],shas[N][3],has1[M],has2[M];
string s[N][3];
vector<int> vt[30];
inline int mod(int x) {
	return x-x/MOD*MOD;
}
void init() {
	p[1]=1;
	for(int i=2; i<=M-5; i++) {
		p[i]=mod(p[i-1]*B);
	}
}
void clearr() {
	ans=0;
	for(int i=1; i<=26; i++)vt[i].clear();
	for(int i=1; i<=n; i++)shas[i][1]=shas[i][2]=0;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	init();
	for(int i=1; i<=n; i++) {
		cin>>s[i][1]>>s[i][2];
		int len=s[i][1].size();
		for(int j=0; j<len; j++) {
			shas[i][1]=mod(shas[i][1]+mod((s[i][1][j]-'a'+1)*p[j+1]));
			shas[i][2]=mod(shas[i][2]+mod((s[i][2][j]-'a'+1)*p[j+1]));
		}
	}
	while(m--) {
		string s1,s2;
		cin>>s1>>s2;
		int lenz=s1.size();
		for(int i=0; i<lenz; i++) {
			vt[s1[i]-'a'+1].push_back(i);
		}
		for(int i=0; i<lenz; i++) {
			has1[i]=mod(has1[i-1]+mod((s1[i]-'a'+1)*p[i+1]));
			has2[i]=mod(has2[i-1]+mod((s2[i]-'a'+1)*p[i+1]));
		}
		for(int i=1; i<=n; i++) {
			int c=s[i][1][1]-'a'+1,lent=s[i][1].size();
			for(int w:vt[c]) {
				if(w+lent-1>=lenz)continue;
				int val=(has1[w+lent-1]-has1[w-1]+MOD)%MOD;
				if(val==mod(shas[i][1]*p[w+1])) {
					int tmp=mod(has1[lenz-1]-mod(p[w+1]*shas[i][0])+mod(p[w+1]*shas[i][1])+MOD);
					if(tmp==has2[lenz-1])ans++;
				}
			}
		}
		cout<<ans<<endl;
		clearr();
	}
	return 0;
}
/*
4 3
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
aa bb

2
0

1 1
bc de
sssbc sssde

1
*/
