#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define il inline
#define pii pair<int,int>
#define x first
#define y second
#define rd read()
#define gc getchar()
#define debug() puts("-----------")

namespace yzqwq{
	il int read(){
		int x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
		while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc;
		return x*f;
	}
	il int qmi(int a,int b,int p){
		int res=1;
		while(b){
			if(b&1) res=res*a%p;
			a=a*a%p,b>>=1;
		}
		return res;
	}
	il int gcd(int a,int b){
		if(!b) return a;
		return gcd(b,a%b);
	}
	il void exgcd(int a,int b,int &x,int &y){
		if(!b) return x=1,y=0,void(0);
		exgcd(b,a%b,y,x);
		y-=a/b*x;
		return ;
	}
	mt19937 rnd(time(0));
}
using namespace yzqwq;

const int N=2e5+10,p=998244353,M=1e6+10;
int n,q,B=12347;
string s[2][N];
string t[2][N];
unordered_map<int,int> mp,Vis;
int idx,res[N];
int r1[N],r2[N];
int l1[N],l2[N];
vector<int> vec[N],vec2[N];
int len,idc[N];
int Len[2][N];
unordered_map<int,bool> itt;
int val[N];
int ll[2][N],rr[2][N];
bitset<64> bt[N],Bt[70];
int stt[N],Idx;
int tr[M];

il void add(int x,int y){
	++x;
	while(x<M) tr[x]+=y,x+=x&(-x);
	return ;
}
il int query(int x){
	++x; int s=0;
	while(x) s+=tr[x],x-=x&(-x);
	return s;
}
il int Id(int x){
	if(!mp.count(x)) return mp[x]=++idx;
	return mp[x];
}
il int Id2(int x){
	if(!Vis.count(x)) return Vis[x]=++Idx;
	return Vis[x];
}

il void solve(){
	n=rd,q=rd;
	for(re int i=1;i<=n;++i) cin>>s[0][i]>>s[1][i];
	for(re int i=1;i<=q;++i) cin>>t[0][i]>>t[1][i];
	bool Flg=0;
	for(re int i=1;i<=n;++i){
		int cc=0;
		for(auto x:s[0][i])
		if(x!='a'&&x!='b') Flg=1;
		else{
			cc+=(x=='b');
		}
		if(cc!=1) Flg=1;
		cc=0;
		for(auto x:s[1][i])
		if(x!='a'&&x!='b') Flg=1;
		else{
			cc+=(x=='b');
		}
		if(cc!=1) Flg=1;
	}
	for(re int i=1;i<=q;++i){
		int cc=0;
		for(auto x:t[0][i])
		if(x!='a'&&x!='b') Flg=1;
		else{
			cc+=(x=='b');
		}
		if(cc!=1) Flg=1;
		cc=0;
		for(auto x:t[1][i])
		if(x!='a'&&x!='b') Flg=1;
		else{
			cc+=(x=='b');
		}
		if(cc!=1) Flg=1;
	}	
	if(!Flg){
		for(re int i=1;i<=n;++i){
			int len=(int)(s[0][i].size());
			val[i]=1;
			Len[0][i]=len;
			int L=len,R=-1;
			for(re int j=0;j<len;++j)
			if(s[0][i][j]!=s[1][i][j]){
				L=min(L,j);
				R=max(R,j);
			}
			if(L<=R){
				ll[0][i]=L,rr[0][i]=R;
				int hs=0;
				for(re int j=L;j<=R;++j){
					hs=(hs*B%p+(s[0][i][j]-'a'+1))%p;
					hs=(hs*B%p+(s[1][i][j]-'a'+1))%p;
				}
				l1[i]=L;
				r1[i]=len-R;
				vec2[Id(hs)].push_back(i);
			}
		}
		for(re int i=1;i<=q;++i){
			int len=(int)(t[0][i].size());
			Len[1][i]=len;
			if((int)(t[1][i].size())!=len){
				res[i]=0;
				continue;
			}
			int L=len,R=-1;
			for(re int j=0;j<len;++j)
			if(t[0][i][j]!=t[1][i][j]){
				L=min(L,j);
				R=max(R,j);
			}
			if(L<=R){
				ll[1][i]=L,rr[1][i]=R;
				int hs=0;
				for(re int j=L;j<=R;++j){
					hs=(hs*B%p+(t[0][i][j]-'a'+1))%p;
					hs=(hs*B%p+(t[1][i][j]-'a'+1))%p;
				}
				l2[i]=L;
				r2[i]=len-R;
				if(!mp.count(hs)) continue;
				vec[Id(hs)].push_back(i);
			}
			else{
				res[i]=0;
				continue;
			}
		}
		for(re int x=1;x<=idx;++x){
			if(vec[x].empty()) continue;
			sort(vec2[x].begin(),vec2[x].end(),[](int x,int y){
				return l1[x]<l1[y];
			});
			sort(vec[x].begin(),vec[x].end(),[](int x,int y){
				return l2[x]<l2[y];
			}); int j=0;
			for(re int i=0;i<(int)(vec[x].size());++i){
				while(j<(int)(vec2[x].size())&&l1[vec2[x][j]]<=l2[vec[x][i]]){
					add(r1[vec2[x][j]],1);
					++j;
				}
				res[vec[x][i]]=query(r2[vec[x][i]]);
			}
			--j;
			while(j>=0){
				add(r1[vec2[x][j]],-1);
				--j;
			}
		}//debug();
		for(re int i=1;i<=q;++i) cout<<res[i]<<"\n";
		return ;
	}
	for(re int i=1;i<=q;++i){
		int len=(int)(t[0][i].size());
		Len[1][i]=len;
		if((int)(t[1][i].size())!=len){
			res[i]=0;
			continue;
		}
		int L=len,R=-1;
		for(re int j=0;j<len;++j)
		if(t[0][i][j]!=t[1][i][j]){
			L=min(L,j);
			R=max(R,j);
		}
		if(L<=R){
			ll[1][i]=L,rr[1][i]=R;
			int hs=0;
			for(re int j=L;j<=R;++j){
				hs=(hs*B%p+(t[0][i][j]-'a'+1))%p;
				hs=(hs*B%p+(t[1][i][j]-'a'+1))%p;
			}
			l2[i]=L;
			r2[i]=len-R;
			vec[Id(hs)].push_back(i);
		}
		else{
			res[i]=0;
			continue;
		}
	}
	for(re int Lid=1;Lid<=n;Lid+=64){
		int Rid=min(n,Lid+63);
		int top=0;
		for(re int i=1;i<=idx;++i) vec2[i].clear();
		for(re int i=Lid;i<=Rid;++i){
			int len=(int)(s[0][i].size());
			val[i]=1;
			Len[0][i]=len;
			int L=len,R=-1;
			for(re int j=0;j<len;++j)
			if(s[0][i][j]!=s[1][i][j]){
				L=min(L,j);
				R=max(R,j);
			}
			if(L<=R){
				ll[0][i]=L,rr[0][i]=R;
				int hs=0;
				for(re int j=L;j<=R;++j){
					hs=(hs*B%p+(s[0][i][j]-'a'+1))%p;
					hs=(hs*B%p+(s[1][i][j]-'a'+1))%p;
				}
				l1[i]=L;
				r1[i]=len-R;
				if(!mp.count(hs)) continue;
				stt[++top]=Id(hs);
				vec2[Id(hs)].push_back(i);
			}
		}
		itt.clear();
//		sort(stt+1,stt+top+1);
//		top=unique(stt+1,stt+top+1)-(top+1);
		for(re int j=1;j<=q;++j) bt[j].reset();
		for(re int ww=1;ww<=top;++ww){
			int x=stt[ww];if(itt.count(x)) continue;
			itt[x]=1;
			for(re int j=1;j<=Idx;++j) Bt[j].reset();
			Vis.clear(); Idx=0;
			for(auto i:vec2[x]){
				int hs=0;
				for(re int j=ll[0][i];j>=0;--j){
					hs=(hs*B%p+(s[0][i][j]-'a'+1))%p;
				}
				Bt[Id2(hs)][i-Lid]=1;
			}
			for(auto i:vec[x]){
				int hs=0;
				for(re int j=ll[1][i];j>=0;--j){
					hs=(hs*B%p+(t[0][i][j]-'a'+1))%p;
					if(Vis.count(hs)) bt[i]|=Bt[Id2(hs)];
				}
			}
			for(re int j=1;j<=Idx;++j) Bt[j].reset();
			Vis.clear();  Idx=0;
			for(auto i:vec2[x]){
				int hs=0;
				for(re int j=rr[0][i];j<Len[0][i];++j){
					hs=(hs*B%p+(s[0][i][j]-'a'+1))%p;
				}
				Bt[Id2(hs)][i-Lid]=1;
			}
			for(auto i:vec[x]){
				int hs=0;
				for(re int j=rr[1][i];j<Len[1][i];++j){
					hs=(hs*B%p+(t[0][i][j]-'a'+1))%p;
					if(Vis.count(hs)){
						res[i]+=(bt[i]&Bt[Id2(hs)]).count();
					}
				}
			}
		}
	}
	for(re int i=1;i<=q;++i) cout<<res[i]<<"\n";
	return ;
}

signed main(){
//	system("fc replace4.ans 11.out");
//	return 0;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t=1;while(t--)
	solve();
	return 0;
}


