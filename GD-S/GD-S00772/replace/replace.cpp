#include <bits/stdc++.h>
#define psb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int N=200010,M=5000010;
int n,Q;
string s1[N],s2[N];

namespace Brute
{
	typedef unsigned long long ull;
	const int P=131;
	ull p[M];
	ull suf[M];
	ull hs1[N],hs2[N];
	ull h[M];
	ull hT[M];
	
	ull get_has(int l,int r) { if (l>r) return 0; return h[r]-h[l-1]*p[r-l+1]; }
	ull get_hasT(int l,int r) { if (l>r) return 0; return hT[r]-hT[l-1]*p[r-l+1]; }
	
	void work()
	{
		p[0]=1; for (int i=1;i<M;i++) p[i]=p[i-1]*P; 
		for (int i=1;i<=n;i++) 
		{
			for (int j=0;j<s1[i].length();j++) hs1[i]=hs1[i]*P+s1[i][j];
			for (int j=0;j<s2[i].length();j++) hs2[i]=hs2[i]*P+s2[i][j];
		}
		
		while (Q--)
		{
			string S,T; cin >> S >> T;
			S=" "+S, T=" "+T;
			int m=S.length();
			for (int i=1;i<=m;i++) h[i]=h[i-1]*P+S[i];
			for (int i=1;i<=m;i++) hT[i]=hT[i-1]*P+T[i];
			for (int i=m;i;i--)
			{
				if (i!=m) suf[i]=suf[i+1];
				else suf[i]=0;
				suf[i]+=p[m-i]*S[i];
			} 
			int ans=0;
			for (int i=1;i<=m;i++)
			{
				for (int j=1;j<=n;j++)
				{
					int k=s1[j].length(); if (i+k-1>m) continue;
					if (get_has(i,i+k-1)!=hs1[j]) continue;
					if (get_has(1,i-1)!=get_hasT(1,i-1)) continue;
					if (get_has(i+k,m)!=get_hasT(i+k,m)) continue;
					if (get_hasT(i,i+k-1)!=hs2[j]) continue;
					ans++;
				}
			}
			cout << ans << "\n";
		}
	}	
}

namespace Subtask
{
	map<PII,vector<int> > mp;
	void work()
	{
		for (int i=1;i<=n;i++) 
		{
			int pos1;for (int j=0;j<s1[i].length();j++) if (s1[i][j]=='b') pos1=j;
			int pos2;for (int j=0;j<s2[i].length();j++) if (s2[i][j]=='b') pos2=j;
			mp[{pos1,pos2}].psb(s1[i].length());
		}
		
		while (Q--)
		{
			string S,T;
			cin >> S >> T;
			int m=S.length();
			int posS; for (int i=0;i<m;i++) if (S[i]=='b') posS=i;
			int posT; for (int i=0;i<m;i++) if (T[i]=='b') posT=i; 
			ll ans=0;
			for (int i=0;i<=min(posS,posT);i++)
			{
				int d1=posS-i, d2=posT-i;
				int p=upper_bound(mp[{d1,d2}].begin(),mp[{d1,d2}].end(),m-i)-mp[{d1,d2}].begin()-1;
				ans+=p+1;
			}
			cout << ans << "\n";
		}
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> Q;
	int sum=0;
	for (int i=1;i<=n;i++) 
	{
		cin >> s1[i] >> s2[i];
		sum+=s1[i].length()+s2[i].length(); 
	}
	if (sum<=2000) Brute::work();
	else Subtask::work(); 
	
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
