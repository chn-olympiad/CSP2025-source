#include <bits/stdc++.h>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
bool st;
const int N = 2e5+5,M = 5e6+5,base1 = 23333,mod1 = 1e9+9,base2 = 20101013,mod2 = 147744151;
inline int qpow(int x,int y,int mod)
{
	int res = 1;
	while(y)
	{
		if(y&1) res = res*x%mod;
		y>>=1;
		x = x*x%mod;
	}
	return res;
}
int pw1[M],inv1[M],pw2[M],inv2[M];
inline void init()
{
	int tmp;
	tmp = qpow(base1,mod1-2,mod1);
	pw1[0] = inv1[0] = 1;
	for(int i = 1;i<N;i++)
		pw1[i] = pw1[i-1]*base1%mod1,inv1[i] = inv1[i-1]*tmp%mod1;
	tmp = qpow(base2,mod2-2,mod2);
	pw2[0] = inv2[0] = 1;
	for(int i = 1;i<N;i++)
		pw2[i] = pw2[i-1]*base2%mod2,inv2[i] = inv2[i-1]*tmp%mod2;
}
int n,q;
string s[2];
int len,h1[2][M],h2[2][M];
inline void inith()
{
	for(int i = 0;i<2;i++)
	{
		for(int j = 1;j<=len;j++)
			h1[i][j] = (h1[i][j-1]+pw1[j]*s[i][j-1])%mod1,
			h2[i][j] = (h2[i][j-1]+pw2[j]*s[i][j-1])%mod2;
	}
}
inline int get(int op,int l,int r)
{
	if(l>r) return 0;
	int res1 = (h1[op][r]-h1[op][l-1]+mod1)*inv1[l-1]%mod1;
	int res2 = (h2[op][r]-h2[op][l-1]+mod2)*inv2[l-1]%mod2;
//	cout<<op<<' '<<l<<' '<<r<<":"<<res1<<' '<<res2<<" "<<res1*mod2+res2<<'\n';
	return res1*mod2+res2;
}
map<pair<pair<int,int>,int>,int> mp;
gp_hash_table<int,int> ton[N];
vector<string> vec[N];
int cnt;
bool en;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	cin>>n>>q;
	for(int i = 1;i<=n;i++)
	{
		cin>>s[0]>>s[1];
		len = s[0].size();
		inith();
		int p1 = 1,p2 = len;
		while(p1<=len&&get(0,1,p1)==get(1,1,p1)) p1++;
		while(p2&&get(0,p2,len)==get(1,p2,len)) p2--;
//		cout<<i<<":"<<p1<<' '<<p2<<'\n';
		pair<pair<int,int>,int> tmp = {{get(0,p1,p2),get(1,p1,p2)},get(0,1,p1-1)};
		if(!mp[tmp]) mp[tmp] = ++cnt;
		int id = mp[tmp];
		string suf;
		for(int i = p2;i<len;i++) suf+=s[0][i];
		vec[id].push_back(suf);
//		ton[id][get(0,p2+1,len)]++; 
	}
	for(int x = 1;x<=cnt;x++)
	{
		sort(vec[x].begin(),vec[x].end(),[&](string x,string y){return x.size()<y.size();});
		ton[x][0] = 1;
//		bool fl = vec[x].size()>=2;
		for(auto s:vec[x])
		{
			int h1 = 0,h2 = 0,len = s.size();
			for(int i = 1;i<=len;i++)
				h1 = (h1+pw1[i]*s[i-1])%mod1,
				h2 = (h2+pw2[i]*s[i-1])%mod2;
			int tmp = h1*mod2+h2;
//			cout<<"xxxxx"<<h1<<' '<<h2<<'\n'; 
			int las = 0;
			for(int i = len;i>=0;i--)
			{
				las = ton[x][h1*mod2+h2];
				if(las)
				{
					for(int j = i+1;j<len;j++)
					{
						h1 = (h1+pw1[j]*s[j-1])%mod1,
						h2 = (h2+pw2[j]*s[j-1])%mod2;
						ton[x][h1*mod2+h2] = las;
					}
					break;
				}
				if(i>0)
				{
					h1 = (h1-pw1[i]*s[i-1])%mod1,
					h2 = (h2-pw2[i]*s[i-1])%mod2;
					h1 = (h1+mod1)%mod1,h2 = (h2+mod2)%mod2;
				}
			}
//			cout<<i<<' '<<tmp<<' '<<las+1<<'\n';
			ton[x][tmp] = las+1;
//			if(fl) cerr<<"xx"<<s.size()<<":"<<tmp<<' '<<las+1<<'\n';
		}
//		if(fl) cerr<<"nxt\n";
	}
//	while(q--)
	for(int _ = 1;_<=q;_++)
	{
		cin>>s[0]>>s[1];
		if(s[0].size()!=s[1].size())
		{
			cout<<"0\n";
			continue;
		}
//		if(_==13) cout<<s[0]<<'\n'<<s[1]<<'\n';
		len = s[0].size();
		inith();
		int p1 = 1,p2 = len;
		while(p1<=len&&get(0,1,p1)==get(1,1,p1)) p1++;
		while(p2&&get(0,p2,len)==get(1,p2,len)) p2--;
//		cout<<p1<<' '<<p2<<'\n';
		int ans = 0; 
		for(int i = 1;i<=p1;i++)
		{
			pair<pair<int,int>,int> tmp = {{get(0,p1,p2),get(1,p1,p2)},get(0,i,p1-1)};
			int id = mp[tmp];
			if(!id) continue;
//			cout<<"xx"<<i<<' '<<id<<'\n';
			int l = p2+1,r = len,res = p2;
			while(l<=r)
			{
				int mid = (l+r)/2;
//				cout<<p2+1<<' '<<mid<<":"<<get(0,p2+1,mid)<<'\n';
				if(ton[id][get(0,p2+1,mid)]) res = mid,l = mid+1;
				else r = mid-1; 
			}
//			cout<<res<<'\n';
			ans+=ton[id][get(0,p2+1,res)]-1;
//			for(int i = len;i>=p2;i--)
//			{
//				if(ton[id][get(0,p2+1,i)])
//				{
//					assert(i==res);
//					break;
//				}
//			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

