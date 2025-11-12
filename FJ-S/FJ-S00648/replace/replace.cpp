// Author: Mr_Az
// 25+ pts: 2025-11-01 17:27:43 process: trie count O(L^2)

#include<bits/stdc++.h>
#define rint register int
#define int long long
#define pb push_back
#define eb emplace_back
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	x=x*f;
	return ;
}
namespace Mr_Az{
	int T=1;
	const int N=2e5+8;
	int n,q;
	vector<int> cnt;
	bool spjB=1;
	string s1[N],s2[N],t1,t2;
	map<int,int> trie[30][30];
	inline void insert(int x){
		#define t trie[s1[x][i]-'a'][s2[x][i]-'a']
		int p=0;
		for(rint i=0;i<(int)(s1[x].size());i++){
			if(t.find(p)==t.end()) t[p]=cnt.size(),cnt.pb(0);
			p=t[p];
		}
		cnt[p]++;
		#undef t
		return ;
	}
	inline void solve(){
		cnt.pb(0);
		read(n);read(q);
		for(rint i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
			insert(i);
		}
		while(q--){
			int p1=0,p2=0,ans=0;
			cin>>t1>>t2;
			if(t1.size()!=t2.size()){puts("0");continue;}
			for(rint i=0;i<(int)(t1.size());i++) if(t1[i]!=t2[i]){p1=i;break;}
			for(rint i=(int)(t1.size())-1;i>=0;i--) if(t1[i]!=t2[i]){p2=i;break;}
			for(rint l=0;l<=p1;l++){
				int p=0;
				#define t trie[t1[r]-'a'][t2[r]-'a']
				for(rint r=l;r<(int)(t1.size());r++){
					if(t.find(p)==t.end()) break;
					p=t[p];
					if(r>=p2) ans+=cnt[p];
				}
				#undef t
			}
			printf("%lld\n",ans);
		} 
		return ;
	}
	inline void mian(){if(!T) read(T);while(T--) solve();}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int st=clock();
	Mr_Az::mian();
	int ed=clock();
	cerr<<"time use: "<<ed-st<<" ms.\n"<<endl;
	return 0;
}

