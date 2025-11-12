#include<bits/stdc++.h>

using namespace std;

const long long p[4]={43849,13331,432894,4394932},mod[4]={1000000007,998244353,1000000009,1000000021};
mt19937 Rand(1145141);
long long n,q,P[4][5000005],inv[4][5000005],val[26],Hash[4][200005][2],HASH[4][5000005][2];
string s[200005][2];
vector<pair<pair<unsigned long long,int>,pair<unsigned long long,int> > >E[10000007];
long long qpow(long long x,long long y,long long mod) {
	long long ans=1;
	while(y) {
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	} 
	return ans;
}
void update(unsigned long long x,unsigned long long c,int len) {
	int now=x%10000007;
	for(auto &i:E[now]) if(i.first.first==x&&i.first.second==len&&i.second.first==c) {
		i.second.second++;
		return;
	}
	E[now].push_back({{x,len},{c,1}});
}
long long get(int op,int l,int r) {
	return (HASH[op][r][0]-HASH[op][l-1][0]*P[op][r-l+1]%mod[op]+mod[op])%mod[op];
}
unsigned long long calc(pair<pair<long long,long long>,pair<long long,long long> >x) {
	return (((unsigned long long)x.first.first*1839475839+x.first.second)*1435672847+x.second.first)*1354578493+x.second.second;
}
int query(unsigned long long x,int t) {
	int now=x%10000007,ans=0;
	for(auto i:E[now]) if(i.first.first==x&&t-i.first.second+1>=1&&calc({{get(0,t-i.first.second+1,t),get(1,t-i.first.second+1,t)},{get(2,t-i.first.second+1,t),get(3,t-i.first.second+1,t)}})==i.second.first) ans+=i.second.second;
	return ans;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<26;i++) val[i]=Rand()%998244352+1;
	for(int i=0;i<4;i++) {
		P[i][0]=inv[i][0]=1;
		long long Inv=qpow(p[i],mod[i]-2,mod[i]);
		for(int j=1;j<=5000000;j++) P[i][j]=P[i][j-1]*p[i]%mod[i],inv[i][j]=inv[i][j-1]*Inv%mod[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>s[i][0]>>s[i][1];
		int S=s[i][0].size();
		for(int j=0;j<4;j++) for(int k=0;k<S;k++) Hash[j][i][0]=(Hash[j][i][0]*p[j]+val[s[i][0][k]-'a'])%mod[j],Hash[j][i][1]=(Hash[j][i][1]*p[j]+val[s[i][1][k]-'a'])%mod[j];
		update(calc({{(Hash[0][i][1]-Hash[0][i][0]+mod[0])%mod[0],(Hash[1][i][1]-Hash[1][i][0]+mod[1])%mod[1]},{(Hash[2][i][1]-Hash[2][i][0]+mod[2])%mod[2],(Hash[3][i][1]-Hash[3][i][0]+mod[3])%mod[3]}}),calc({{Hash[0][i][0],Hash[1][i][0]},{Hash[2][i][0],Hash[3][i][0]}}),S);
	}
	while(q--) {
		long long S,ans=0;
		string t[2];
		cin>>t[0]>>t[1],S=t[0].size();
		if(S!=t[1].size()) {
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<4;i++) for(int j=1;j<=S;j++) HASH[i][j][0]=(HASH[i][j-1][0]*p[i]+val[t[0][j-1]-'a'])%mod[i],HASH[i][j][1]=(HASH[i][j-1][1]*p[i]+val[t[1][j-1]-'a'])%mod[i];
		for(int i=0;i<S;i++) ans+=query(calc({{(HASH[0][S][1]-HASH[0][S][0]+mod[0])%mod[0]*inv[0][S-i-1]%mod[0],(HASH[1][S][1]-HASH[1][S][0]+mod[1])%mod[1]*inv[1][S-i-1]%mod[1]},{(HASH[2][S][1]-HASH[2][S][0]+mod[2])%mod[2]*inv[2][S-i-1]%mod[2],(HASH[3][S][1]-HASH[3][S][0]+mod[3])%mod[3]*inv[3][S-i-1]%mod[3]}}),i+1);
		cout<<ans<<"\n";
	}
	return 0;
}
