
// Surpassing never ends!

#include<bits/stdc++.h>
#define ll long long
//#define int long long 
using namespace std;
const int N=5e6+500,M=1e6+100;
const ll P=1285963477;
long long read() {
	long long x=0;
//	cin>>x;return x;
	short f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-')f=-1;c=getchar(); }
	while(c>='0'&&c<='9') { x=x*10+c-'0';c=getchar(); }
	return x*f;
}
bool MB_1;

int n,Q,tot1,tot2,id[N],l1[N],l2[N];

char s1[N],s2[N],t1[N],t2[N];

map<int ,int > tr1[N];
map<int ,int > tr2[N];

vector<int > ed[N];bitset<N >e1,e2;

void ins(int x) {
	int nw=0,len=strlen(s1+1);
	for(int i=1;i<=len;i++) {
		int op=s1[i]-'a';
		if(!tr1[nw][op]) tr1[nw][op]=++tot1;
		nw=tr1[nw][op];
		l1[nw]=i;
	}
	ed[nw].push_back(x);e1[nw]=1;
	nw=0,len=strlen(s2+1);
	for(int i=1;i<=len;i++) {
		int op=s2[i]-'a';
		if(!tr2[nw][op]) tr2[nw][op]=++tot2;
		nw=tr2[nw][op];
		l2[nw]=i;
	}
	id[x]=nw;e2[nw]=1;
}

int fl1[N],fl2[N];

vector<int > b1[N],b2[N];

queue<int > q;
void build() {
	for(int i=0;i<26;i++) if(tr1[0].count(i)) q.push(tr1[0][i]);
	while(!q.empty()) {
		int k=q.front();q.pop();
		b1[fl1[k]].push_back(k);
		for(int i=0;i<26;i++) if(tr1[k].count(i)) {
			fl1[ tr1[k][i] ]=tr1[ fl1[k] ][i];
			q.push(tr1[k][i]);
		}
		else tr1[k][i]=tr1[fl1[k]][i];
	}
	for(int i=0;i<26;i++) if(tr2[0].count(i)) q.push(tr2[0][i]);
	while(!q.empty()) {
		int k=q.front();q.pop();
		b2[fl2[k]].push_back(k);
		for(int i=0;i<26;i++) if(tr2[k].count(i)) {
			fl2[ tr2[k][i] ]=tr2[ fl2[k] ][i];
			q.push(tr2[k][i]);
		}
		else tr2[k][i]=tr2[fl2[k]][i];
	}
}
void df1(int p,int zs) {
	fl1[p]=zs;if(e1[p]) zs=p;
	for(int i:b1[p]) df1(i,zs);
}
void df2(int p,int zs) {
	fl2[p]=zs;if(e2[p]) zs=p;
	for(int i:b2[p]) df2(i,zs);
}

ll qry(int L,int R,int len) {
	int nw1=0,nw2=0;ll res=0;
	for(int i=1;i<=len;i++) {
		nw1=tr1[nw1][t1[i]-'a'];
		nw2=tr2[nw2][t2[i]-'a'];
		if(i<R) continue;
		int w1=nw1,w2=nw2;
		while(w1&&w2) { 
			while(l1[w1]^l2[w2]) {
				if(l1[w1]>l2[w2]) w1=fl1[w1];
				else w2=fl2[w2];
			}
			if(R-l1[w1]>=L) break;
			for(int j:ed[w1]) if(id[j]==w2) {
				res++;
//				cout<<w1<<" "<<w2<<" "<<j<<'\n';
			}
			w1=fl1[w1],w2=fl2[w2];
		}
	}
	return res;
}

ll le[1010],h1[1010][2020],h2[1010][2020],hs1[2020],hs2[2020];

ll pw[2010];

bool check(int z,int l,int r) {
	if(h1[z][le[z]]!=(hs1[r]-hs1[l-1]*pw[r-l+1]%P+P)%P) return 0;
	if(h2[z][le[z]]!=(hs2[r]-hs2[l-1]*pw[r-l+1]%P+P)%P) return 0;
	return 1;
}

bool MB_2;

signed main() {
//	cerr<<fabs(&MB_2-&MB_1)/(1024*1024)<<"MB\n";
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	if(n<=1000) {
		pw[0]=1;
		for(int i=1;i<=2000;i++) pw[i]=pw[i-1]*911%P;
		for(int i=1;i<=n;i++) {
			scanf("%s",s1+1);
			scanf("%s",s2+1);
			le[i]=strlen(s1+1);
			for(int j=1;j<=le[i];j++) {
				h1[i][j]=(h1[i][j-1]*911+s1[j]-'a')%P;
				h2[i][j]=(h2[i][j-1]*911+s2[j]-'a')%P;
			}
		}
		for(int i=1;i<=Q;i++) {
			scanf("%s",t1+1);
			scanf("%s",t2+1);
			int len=strlen(t1+1);
			int L=len,R=0,ans=0;
			for(int j=1;j<=len;j++) {
				if(t1[j]!=t2[j]) {
					L=min(L,j),R=max(R,j); 
				}
				hs1[j]=(hs1[j-1]*911+t1[j]-'a')%P;
				hs2[j]=(hs2[j-1]*911+t2[j]-'a')%P;
			}
			for(int j=R;j<=len;j++) 
				for(int z=1;z<=n;z++) if(j-le[z]+1>=1&&j-le[z]+1<=L){
					if(check(z,j-le[z]+1,j)) ans++;
				}
			cout<<ans<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++) {
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		ins(i);
	}
	build();df1(0,0),df2(0,0);
	for(int i=1;i<=Q;i++) {
		scanf("%s",t1+1);
		scanf("%s",t2+1);
		int len=strlen(t1+1);
		int L=len,R=0;
		for(int j=1;j<=len;j++) if(t1[j]!=t2[j]) {
			L=min(L,j),R=max(R,j); 
		}
		printf("%lld\n",qry(L,R,len));
	}
	return 0;
}
