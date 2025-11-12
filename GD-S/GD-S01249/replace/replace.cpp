#include <bits/stdc++.h>
#define up(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define dn(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define fst first
#define sed second
#define Max(x,y) (((x)>(y))?(x):(y))
#define Min(x,y) (((x)<(y))?(x):(y))
#define Abs(x) (((x)<0)?(-(x)):(x))
using namespace std;
using ll=long long;using ull=unsigned long long;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pil=pair<int,ll>;
using pli=pair<ll,int>;using vi=vector<int>;
namespace my{
	const int N=(int)(2e5+2),L=(int)(5e6+2),SL=2239;
	const ull base=131;
	string s[N][2];
	int lenf[N];
	ull hashs[N][2];
	ull pre[L],suf[L],pres[L],sufs[L],pw[L];
	int boxlen[L],idx[L];
	vi gotlen;
	int n,q;
	inline ull querya(int l,int r){
		return pre[r]-pre[l-1]*pw[r-l+1];
	}
	inline ull queryb(int l,int r){
		return pres[r]-pres[l-1]*pw[r-l+1];
	}
	map<pair<ull,ull>,int>mp[SL];
	inline void SOLVE(){
		cin>>n>>q;
		up(i,1,n)cin>>s[i][0]>>s[i][1],lenf[i]=(int)s[i][0].length(),boxlen[lenf[i]]++;
		pw[0]=1;up(i,1,L){
			if(boxlen[i])gotlen.push_back(i);
			pw[i]=pw[i-1]*base;
		}
		reverse(gotlen.begin(),gotlen.end());
		int lenlen=(int)gotlen.size();
		up(i,0,lenlen-1)idx[gotlen[i]]=i+1;
		up(i,1,n){
			up(j,0,lenf[i]-1)hashs[i][0]=hashs[i][0]*base+s[i][0][j];
			up(j,0,lenf[i]-1)hashs[i][1]=hashs[i][1]*base+s[i][1][j];
			mp[idx[lenf[i]]][{hashs[i][0],hashs[i][1]}]++;
		}
		while(q--){
			string a,b;cin>>a>>b;
			int len=(int)a.length();
			a=" "+a,b=" "+b;
			pre[0]=pres[0]=suf[len+1]=sufs[len+1]=0;
			up(i,1,len)
				pre[i]=pre[i-1]*base+a[i],
				pres[i]=pres[i-1]*base+b[i];
			dn(i,len,1)
				suf[i]=suf[i+1]*base+a[i],
				sufs[i]=sufs[i+1]*base+b[i];
			ll ans=0;
			dn(i,len,1){
				if(pre[i-1]!=pres[i-1])continue;
				for(int v:gotlen){
					if(i+v-1>len)continue;
					if(suf[i+v]!=sufs[i+v])break;
					ull ahash=querya(i,i+v-1),bhash=queryb(i,i+v-1);
					if(suf[i+v]==sufs[i+v]&&mp[idx[v]].find({ahash,bhash})!=mp[idx[v]].end())
							ans+=mp[idx[v]][{ahash,bhash}];
				}
			}
			cout<<ans<<'\n';
		}
	}
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	my::SOLVE();return 0;
}
/*
about square root ?
We should find a new solution faster than O(L sqrt(L)) 
Becuase the different types of the string of length is lower than sqrt(L)
because n*(n-1)/2=1+...+n and than we can use hash to make it faster
I think this solution will get a high score
Intel Core Ultra 9 285k CPU @ 3.70 GHz will help me to Ac this problem
but I can't solve the T1 
o bro I think this solution is O(1/4 L sqrt(L)) becuase L=|si0|+|si1| so |si0=L/2 
don't hack my hash_base!

1~i-1 
i~i+v-1
i+v~len

oh no! pair<ull,ull> can't use unordered_map !!!

no!

the big pretest 4 3.897s !!!

let's write a fast read slower than cin :(

2.29s!!!

2.26s!!!

1.041s!!!
*/
