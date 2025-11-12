#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
#define db double
#define pb push_back
#define vec vector
#define fi first
#define se second
#define lwz lower_bound
#define lowbit(x) (x&(-x))
#define popc(x) __builtin_popcount(x)
#define ull unsigned long long
#define il inline
using namespace std;
std:: mt19937 rng(time(0));
const int M=2e5+5;
const int N=5e6+5;
const int base=131;
int mod[2]={998244353,(int)(1e9+7)};
vec<PII>ha[2][N];
int n,q,ba[2][M],le[N];
PII hh[2][M];
string s[2],t[2];
PII get(int i,int j,int l,int r){
	int x=(ha[i][j][r].fi-1ll*ha[i][j][l-1].fi*ba[0][r-l+1]%mod[0])%mod[0];
	int y=(ha[i][j][r].se-1ll*ha[i][j][l-1].se*ba[1][r-l+1]%mod[1])%mod[1];
	if(x<0)x+=mod[0];
	if(y<0)y+=mod[1];
	return {x,y};
}
PII get2(int i,int l,int r){
	int x=(hh[i][r].fi-1ll*hh[i][l-1].fi*ba[0][r-l+1]%mod[0])%mod[0];
	int y=(hh[i][r].se-1ll*hh[i][l-1].se*ba[1][r-l+1]%mod[1])%mod[1];
	if(x<0)x+=mod[0];
	if(y<0)y+=mod[1];
	return {x,y};
}
il void work(){
	int maxx=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[0]>>s[1];
		int len=s[0].size();
		le[i]=len;
		maxx=max(maxx,len);
		ha[0][i].resize(len+5),ha[1][i].resize(len+5);
		for(int j=0;j<2;j++){
			for(int k=0;k<len;k++){
				ha[j][i][k+1].fi=(1ll*ha[j][i][k].fi*base%mod[0]+s[j][k])%mod[0];
				ha[j][i][k+1].se=(1ll*ha[j][i][k].se*base%mod[1]+s[j][k])%mod[1];
			}
		}
	}
	ba[0][0]=ba[1][0]=1; 
	for(int j=0;j<2;j++){
		for(int i=1;i<=maxx;i++)ba[j][i]=1ll*ba[j][i-1]*base%mod[j];
	} 
	while(q--){
		cin>>t[0]>>t[1];
		int len=t[0].size();
		int l=-1,r=-1;
		for(int i=0;i<len;i++){
			if(t[0][i]!=t[1][i]){
				if(l==-1)l=i;
				r=i;
			}
		}
		for(int j=0;j<2;j++){
			for(int i=0;i<len;i++){
				hh[j][i+1].fi=(1ll*hh[j][i].fi*base%mod[0]+t[j][i])%mod[0];
				hh[j][i+1].se=(1ll*hh[j][i].se*base%mod[1]+t[j][i])%mod[1];
			}			
		}
		l++,r++;
		int op=r-l+1,ans=0;
		for(int i=1;i<=n;i++){
			if(le[i]<op)continue;
			for(int L=1;L<=le[i]-op+1;L++){
				int R=L+op-1;
				if(L-1>l-1)continue;
				if(le[i]-R>len-r)continue;
				if(get(0,i,L,R)==get2(0,l,r)&&get(1,i,L,R)==get2(1,l,r)){
					int llen=L,rlen=le[i]-R+1;
					if(get(0,i,1,le[i])==get2(0,l-llen+1,r+rlen-1)&&get(1,i,1,le[i])==get2(1,l-llen+1,r+rlen-1))ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int TTT=1;;
	while(TTT--)work();
	return 0;
} /*
首先我们需要找到第一个字符串和第二个字符串不同的区间
发掘一下性质
首先替换的那个区间一定要完全包含含有不同字符的区间
然后替换前替换后的区间一定要有个公共的前缀和后缀，并且还要匹配原串
性质A:把那个区间挖出来，然后在每个替换上面匹配一下
性质B： 我不会啊啊啊啊
靠了为啥考串串题啊。。。。。 
*/
