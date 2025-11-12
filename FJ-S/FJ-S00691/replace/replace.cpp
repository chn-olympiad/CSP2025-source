#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 vl;
const int N=210000,M=5100000,B=26;
const ll base=233327,mod=(ll)(1e18)+3;
int n,q,L,R;
char ss[M];
inline string read(){
	scanf("%s",ss+1);
	string res;
	int len=strlen(ss+1);
	for(int i=1;i<=len;i++)
		res.push_back(ss[i]);
	return res;
}
string s[N],t[N],S[N],T[N];
struct node{
	ll a,b;
	int l,r,i;
}a[N],b[N];
ll p[N],hsh[N];
inline ll hs(int l,int r){
	return ((hsh[r]-(vl)hsh[l-1]*p[r-l+1])%mod+mod)%mod;
}
int ans[N];
struct tra{
	int nw,son[M][B];
	inline void clear(){
		while(nw){
			for(int c=0;c<B;c++)
				son[nw][c]=0;
			nw--;
		}
		nw=1;
		t=0;
	}
	int t,dfn[M],low[M];
	void dfs(int x){
		dfn[x]=++t;
		for(int c=0;c<B;c++)
			if(son[x][c])
				dfs(son[x][c]);
		low[x]=t;
	}
}doga;
int Dfn[M][2],Low[M][2];
int f[N][2],g[N][2];
struct strb{
	int n;
	int a[M];
	inline int lowbit(int x){
		return x&-x;
	}
	inline void clear(){
		for(int i=1;i<=n;i++)
			a[i]=0;
	}
	inline void p(int x,int z){
		for(int i=x;i<=n;i+=lowbit(i))
			a[i]+=z;
	}
	inline void p(int x,int y,int z){
		p(x,z),p(y+1,-z);
	}
	inline int q(int x){
		int res=0;
		for(int i=x;i;i-=lowbit(i))
			res+=a[i];
		return res;
	}
}dogb;
void solve(int la,int ra,int lb,int rb){
	doga.clear();
	for(int i=la;i<=ra;i++){
		int x=1;
		for(int k=a[i].l;k;k--){
			int c=s[a[i].i][k-1]-'a';
			if(doga.son[x][c]==0||doga.son[x][c]>doga.nw)
				doga.son[x][c]=++doga.nw;
			x=doga.son[x][c];
		}
		f[i][0]=x;
	}
	doga.dfs(1);
	for(int i=lb;i<=rb;i++){
		int x=1;
		for(int k=b[i].l;k;k--){
			int c=S[b[i].i][k-1]-'a';
			if(doga.son[x][c]==0)
				break;
			x=doga.son[x][c];
		}
		f[i][1]=x;
	}
	for(int i=1;i<=doga.nw;i++)
		Dfn[i][0]=doga.dfn[i],Low[i][0]=doga.low[i];
	dogb.n=doga.nw;
	dogb.clear();
	doga.clear();
	for(int i=la;i<=ra;i++){
		int x=1;
		for(int k=a[i].r;k<=(int)s[a[i].i].size();k++){
			int c=s[a[i].i][k-1]-'a';
			if(doga.son[x][c]==0||doga.son[x][c]>doga.nw)
				doga.son[x][c]=++doga.nw;
			x=doga.son[x][c];
		}
		g[i][0]=x;
	}
	doga.dfs(1);
	for(int i=lb;i<=rb;i++){
		int x=1;
		for(int k=b[i].r;k<=(int)S[b[i].i].size();k++){
			int c=S[b[i].i][k-1]-'a';
			if(doga.son[x][c]==0)
				break;
			x=doga.son[x][c];
		}
		g[i][1]=x;
	}
	for(int i=1;i<=doga.nw;i++)
		Dfn[i][1]=doga.dfn[i],Low[i][1]=doga.low[i];
	vector <pair<int,array<int,3>>> add;
	for(int i=la;i<=ra;i++){
		add.push_back({Dfn[g[i][0]][1],{Dfn[f[i][0]][0],Low[f[i][0]][0],1}});
		add.push_back({Low[g[i][0]][1]+1,{Dfn[f[i][0]][0],Low[f[i][0]][0],-1}});
	}
	sort(add.begin(),add.end(),[](const auto x,const auto y){
		return x.first<y.first;
	});
	vector <pair<int,pair<int,int>>> ask;
	for(int i=lb;i<=rb;i++)
		ask.push_back({Dfn[g[i][1]][1],{Dfn[f[i][1]][0],b[i].i}});
	sort(ask.begin(),ask.end(),[](const auto x,const auto y){
		return x.first<y.first;
	});
	reverse(add.begin(),add.end());
	for(auto it:ask){
		while(add.empty()==0&&add.back().first<=it.first){
			dogb.p(add.back().second[0],add.back().second[1],add.back().second[2]);
			add.pop_back(); 
		}
		ans[it.second.second]=dogb.q(it.second.first);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		s[i]=read(),t[i]=read();
		int len=s[i].size();
		int l=-1,r=len;
		while(l+1<len&&s[i][l+1]==t[i][l+1])
			l++;
		while(r>0&&s[i][r-1]==t[i][r-1])
			r--;
		l++,r++;
		if(l==len)
			continue;
		p[0]=1;
		for(int j=1;j<=len;j++)
			p[j]=(vl)p[j-1]*base%mod;
		for(int j=1;j<=len;j++)
			hsh[j]=((vl)hsh[j-1]*base+s[i][j-1])%mod;
		ll A=hs(l+1,r-1);
		for(int j=1;j<=len;j++)
			hsh[j]=((vl)hsh[j-1]*base+t[i][j-1])%mod;
		ll B=hs(l+1,r-1);
		L++;
		a[L].a=A;
		a[L].b=B;
		a[L].l=l;
		a[L].r=r;
		a[L].i=i;
	}
	for(int i=1;i<=q;i++){
		S[i]=read(),T[i]=read();
		if(S[i].size()!=T[i].size())
			continue;
		int len=S[i].size();
		int l=-1,r=len;
		while(l+1<len&&S[i][l+1]==T[i][l+1])
			l++;
		while(r>0&&S[i][r-1]==T[i][r-1])
			r--;
		l++,r++;
		if(l==len)
			continue;
		p[0]=1;
		for(int j=1;j<=len;j++)
			p[j]=(vl)p[j-1]*base%mod;
		for(int j=1;j<=len;j++)
			hsh[j]=((vl)hsh[j-1]*base+S[i][j-1])%mod;
		ll A=hs(l+1,r-1);
		for(int j=1;j<=len;j++)
			hsh[j]=((vl)hsh[j-1]*base+T[i][j-1])%mod;
		ll B=hs(l+1,r-1);
		R++;
		b[R].a=A;
		b[R].b=B;
		b[R].l=l;
		b[R].r=r;
		b[R].i=i;
	}
	sort(a+1,a+L+1,[](const node x,const node y){
		return x.a!=y.a?x.a<y.a:x.b<y.b;
	});
	sort(b+1,b+R+1,[](const node x,const node y){
		return x.a!=y.a?x.a<y.a:x.b<y.b;
	});
	for(int i=1,j=1;i<=L&&j<=R;){
		if(a[i].a!=b[j].a){
			if(a[i].a<b[j].a)
				i++;
			else
				j++;
			continue;
		}
		if(a[i].b!=b[j].b){
			if(a[i].b<b[j].b)
				i++;
			else
				j++;
			continue;
		}
		int I=i,J=j;
		while(I<L&&a[i].a==a[I+1].a&&a[i].b==a[I+1].b)
			I++;
		while(J<R&&b[j].a==b[J+1].a&&b[j].b==b[J+1].b)
			J++;
		solve(i,I,j,J);
		i=I+1,j=J+1;
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
