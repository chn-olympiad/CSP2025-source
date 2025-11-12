#include<bits/stdc++.h>
#define int long long

/*
hash sum 1e12

sqrt((1e16)^2) is ok

i want to find a 1e16 prime
10000000000000069

base is big, i want to use __int128
*/

using namespace std;

const int bse=67108879,mod1=10000000000001549,mod2=10000000000001551,N=200005,mod=10007;

int n,q;
int delta[N][2];
unordered_map<int,unordered_map<int,int>> M[100005];

int qmod(int n,int k,int mod) {
	if(k==0) return bool(n);
	if(k&1) return (__int128)qmod((__int128)n*n%mod,k/2,mod)*n%mod;
	else return qmod((__int128)n*n%mod,k/2,mod);
}

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> n >> q;

	string s1,s2;
	
	int hashs1_1=0,hashs1_2=0,hashs2_1=0,hashs2_2=0,m=0;
	for(int i=1;i<=n;++i) {
		cin >> s1 >> s2;
		m=s1.size();
		hashs1_1=0,hashs1_2=0,hashs2_1=0,hashs2_2=0;
		for(int j=0;j<m;++j) {
			hashs1_1 = ((__int128)hashs1_1 * bse + (1ll<<(s1[j]-'a'))) % mod1;
			hashs1_2 = ((__int128)hashs1_2 * bse + (1ll<<(s1[j]-'a'))) % mod2;

			hashs2_1 = ((__int128)hashs2_1 * bse + (1ll<<(s2[j]-'a'))) % mod1;
			hashs2_2 = ((__int128)hashs2_2 * bse + (1ll<<(s2[j]-'a'))) % mod2;
//			cout << "V" << hashs1_1 << ' ' << hashs2_1 << ' ' << hashs1_2 << ' ' << hashs2_2 << '\n';
		}

		int sm=0;
		for(int j=0;j<=5;++j)
			if(m-j-1>=0)
				sm=(sm*27+(s1[m-j-1]-'a'+1))%mod;

		M[sm][(hashs1_1 - hashs2_1 + mod1) % mod1][(hashs1_2 - hashs2_2 + mod2) % mod2]++;
//		cout << (hashs1_1 - hashs2_1 + mod1) % mod1 << ' ' << (hashs1_2 - hashs2_2 + mod2) % mod2 << '\n';
	}

	int fbse1 = qmod(bse,mod1-2,mod1),fbse2 = qmod(bse,mod2-2,mod2);
	for(int i=1;i<=q;++i) {
		cin >> s1 >> s2;
		m=s1.size();
		hashs1_1=0,hashs1_2=0,hashs2_1=0,hashs2_2=0;
		for(int j=0;j<m;++j) {
			hashs1_1 = ((__int128)hashs1_1 * bse + (1ll<<(s1[j]-'a'))) % mod1;
			hashs1_2 = ((__int128)hashs1_2 * bse + (1ll<<(s1[j]-'a'))) % mod2;

			hashs2_1 = ((__int128)hashs2_1 * bse + (1ll<<(s2[j]-'a'))) % mod1;
			hashs2_2 = ((__int128)hashs2_2 * bse + (1ll<<(s2[j]-'a'))) % mod2;
		}

//		cout << hashs1_1 << ' ' << hashs2_1 << ' ' << hashs1_2 << ' ' << hashs2_2 << '\n';
		int c1 = (hashs1_1 - hashs2_1 + mod1) % mod1, c2 = (hashs1_2 - hashs2_2 + mod2) % mod2,ans=0;
//		cout << c1 << ' ' << c2 << '\n';
		for(int j=0;j<m;++j) {
			int sm=0;
			for(int j_=0;j_<=5;++j_)
				if(m-j-j_-1>=0)
					sm=(sm*27+(s1[m-j-j_-1]-'a'+1))%mod,
					ans+=M[sm][c1][c2];
			c1 = (__int128)c1*fbse1%mod1;
			c2 = (__int128)c2*fbse2%mod2;
//			cout << c1 << ' ' << c2 << '\n';
		}
		cout << ans << '\n';
	}

	return 0;
}