#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+5,L=5e6+5;
int n,q,nx[N],pr[N],ans,le[N];
string s[N][2];
const ll cf=53,mo=993432443;
vector<ll>ha[N][2];
ll hs[2][L],pw[L];
bool com(int i,int l,int r) {
	ll h0,h1;
	if(l==0) h0=hs[0][r],h1=hs[1][r];
	else h0=(hs[0][r]-hs[0][l-1]*pw[r-l+1]%mo+mo)%mo,h1=(hs[1][r]-hs[1][l-1]*pw[r-l+1]%mo+mo)%mo;
	if(ha[i][0][le[i]]==h0&&ha[i][1][le[i]]==h1) return 1;
	return 0;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q; 
	pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*cf%mo; 
	for(int i=1;i<=n;i++) {
	    cin>>s[i][0]>>s[i][1];
		le[i]=s[i][0].length()-1;
		nx[i]=le[i];
		while(pr[i]<=le[i]&&s[i][0][pr[i]]==s[i][1][pr[i]]) pr[i]++;
		while(nx[i]&&s[i][0][nx[i]]==s[i][1][nx[i]]) nx[i]--;
	    for(int j=0;j<=1;j++) {
	    	ll h=0;
	    	for(int k=0;k<=le[i];k++) {
	    		h=(h*cf+s[i][j][k]-'a')%mo;
	    		ha[i][j].push_back(h);
			}
		}
	}
	while(q--) {
		cin>>s[0][0]>>s[0][1];
		if(s[0][0].length()!=s[0][1].length()) {
			printf("0\n");
			continue ;
		}
		le[0]=s[0][0].length()-1;
		pr[0]=0,nx[0]=le[0],ans=0;
		while(pr[0]<=le[0]&&s[0][0][pr[0]]==s[0][1][pr[0]]) pr[0]++;
		while(nx[0]&&s[0][0][nx[0]]==s[0][1][nx[0]]) nx[0]--;
		//处理出最长不等区间
		for(int j=0;j<=1;j++) {
	    	ll h=0;
	    	for(int k=0;k<=le[0];k++) {
	    		h=(h*cf+s[0][j][k]-'a')%mo;
	    		hs[j][k]=h;
			}
		}
		for(int i=1;i<=n;i++) {
			if(nx[0]-pr[0]!=nx[i]-pr[i]||le[i]>le[0]) continue ;
			int st=pr[0]-pr[i],ed=nx[0]+le[i]-nx[i];
			if(com(i,st,ed)) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

