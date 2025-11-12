#include <bits/stdc++.h>
using namespace std;

#define pr pair
#define fst first
#define scd second
#define mkpr make_pair
#define MOD1 998244353
#define MOD2 1000000007
#define MOD3 2147483647
#define MAXN 2000005

namespace akakakak{

	inline long long Pow(long long down, long long up, long long mod){
		long long res=1;
		down%=mod;
		while (up){
			if (up&1) res=res*down%mod;
			down=down*down%mod;
			up>>=1;
		}
		return res;
	}

	inline long long Inv(long long down, long long mod){
		return Pow(down, mod-2, mod);
	}

	struct hn{
		long long k1, k2, k3;			// (17, 998244353), (7, 1000000007), ({prime}, 2147483647)
		hn (): k1(0), k2(0), k3(0) {}
		inline bool operator == (const hn &rhs)const{
			return (k1==rhs.k1) && (k2==rhs.k2) && (k3==rhs.k3);
		}
		inline bool operator < (const hn &rhs)const{
			return (k1!=rhs.k1)?(k1<rhs.k1):((k2!=rhs.k2)?(k2<rhs.k2):(k3<rhs.k3));
		}
		inline bool operator > (const hn &rhs)const{
			return (k1!=rhs.k1)?(k1>rhs.k1):((k2!=rhs.k2)?(k2>rhs.k2):(k3>rhs.k3));
		}
	};

	long long prime[MAXN];
	bool isnprime[MAXN];
	long long pow17[MAXN], pow7[MAXN];
	inline void Init(){
		pow17[0]=pow7[0]=1;
		pow17[1]=2; pow7[1]=7;
		for (int i=2;i<MAXN;++i){
			pow17[i]=pow17[i-1]*17%MOD1;
			pow7[i]=pow7[i-1]*7%MOD2;
			if (!isnprime[i]) prime[++prime[0]]=i;
			for (int j=1;j<=prime[0];++j){
				long long got=prime[j]*i;
				if (got>=MAXN) break;
				isnprime[got]=1;
				if (!(i%prime[j])) break;
			}
		}
		return;
	}

	int n, q;
	string s1, s2;
	string t1, t2;
	pr <hn, hn> lst[MAXN];

	inline bool Check(const pr<hn, hn> &rhs){
		return *lower_bound(lst+1, lst+n+1, rhs)==rhs;
	}

	int main(){
		Init ();
		cin>>n>>q;
		for (int i=1;i<=n;++i){
			cin>>s1>>s2;
			int len=s1.length();
			for (int j=0;j<len;++j){
				lst[i].fst.k1=(lst[i].fst.k1+(s1[j]-'a'+1)*pow17[j]%MOD1)%MOD1;
				lst[i].fst.k2=(lst[i].fst.k2+(s1[j]-'a'+1)*pow7[j]%MOD2)%MOD2;
				lst[i].fst.k3=(lst[i].fst.k3+(s1[j]-'a'+1)*prime[j]%MOD3)%MOD3;
				lst[i].scd.k1=(lst[i].scd.k1+(s2[j]-'a'+1)*pow17[j]%MOD1)%MOD1;
				lst[i].scd.k2=(lst[i].scd.k2+(s2[j]-'a'+1)*pow7[j]%MOD2)%MOD2;
				lst[i].scd.k3=(lst[i].scd.k3+(s2[j]-'a'+1)*prime[j]%MOD3)%MOD3;
			}
			// cout<<i<<": "<<lst[i].fst.k1<<" "<<lst[i].fst.k2<<" "<<lst[i].fst.k3<<" "<<lst[i].scd.k1<<" "<<lst[i].scd.k2<<" "<<lst[i].scd.k3<<endl;
		}
		sort (lst+1, lst+n+1);
		while (q --> 0){
			cin>>t1>>t2;
			int len=t1.length();
			int p1=0, p2=len-1;
			while (p1<len && t1[p1]==t2[p1]) ++p1;
			while (~p2 && t1[p2]==t2[p2]) --p2;
			int ans=0;
			for (int i=-1;i<p1;++i){
				hn res1, res2;
				for (int j=i+1;j<len;++j){
					res1.k1=(res1.k1+(t1[j]-'a'+1)*pow17[j-i-1]%MOD1)%MOD1;
					res1.k2=(res1.k2+(t1[j]-'a'+1)*pow7[j-i-1]%MOD2)%MOD2;
					res1.k3=(res1.k3+(t1[j]-'a'+1)*prime[j-i-1]%MOD3)%MOD3;
					res2.k1=(res2.k1+(t2[j]-'a'+1)*pow17[j-i-1]%MOD1)%MOD1;
					res2.k2=(res2.k2+(t2[j]-'a'+1)*pow7[j-i-1]%MOD2)%MOD2;
					res2.k3=(res2.k3+(t2[j]-'a'+1)*prime[j-i-1]%MOD3)%MOD3;
					// if (j>=p2) ans+=Check(mkpr(res1, res2));
					if (j>=p2){
						if (Check(mkpr(res1, res2))){
							++ans;
							// cout<<i+1<<" "<<j<<endl;
							// cout<<res1.k1<<" "<<res1.k2<<" "<<res1.k3<<" "<<res2.k1<<" "<<res2.k2<<" "<<res2.k3<<endl;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
}

int main(){
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	return akakakak::main();
}
