#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define db double
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int MAXX=2e5+10;
const int MAXL=5e6+10;
const ll bas=2333;			//记得改回来 
const ll P=998244353;

int n,q,fbt=1;
string a[MAXX][2],b[MAXX][2];
bool spe(string s) {
	int len=s.size(),res=0;
	for(int i=0;i<len;i++) {
		if(s[i]=='a') continue;
		if(s[i]=='b') res++;
		else return 0;
	}
	if(res==1) return 1;
	return 0;
}
int get_pos(string s) {
	int len=s.size(),pos=0;
	for(int i=0;i<len;i++) {
		if(s[i]=='b') { pos=i; break; }
	}
	return pos;
}
int cntb=0;
struct Data {
	int w,x,y,id;
	bool operator<(const Data &rhs) const {
		if(w!=rhs.w) return w<rhs.w;
		if(x!=rhs.x) return x<rhs.x;
		return y<rhs.y;
	}
}ft[MAXX],qt[MAXX];
int ans[MAXX],c[MAXL];
void add(int x,int w) {
	for(;x<MAXL;x+=(x&(-x))) c[x]+=w;
}
int ask(int x) {
	int res=0;
	for(;x;x-=(x&(-x))) res+=c[x];
	return res;
}
void solb() {
	for(int i=1;i<=n;i++) {
		int pos1=get_pos(a[i][0]),pos2=get_pos(a[i][1]),len=a[i][0].size();
		if(pos1<pos2) ft[i]=(Data){pos2-pos1,pos1,len-pos2-1,0};
		else if(pos2<pos1) ft[i]=(Data){-(pos1-pos2),pos2,len-pos1-1,0};
	}
	sort(ft+1,ft+1+n);
//	for(int i=1;i<=n;i++) cout<<ft[i].w<<" "<<ft[i].x<<" "<<ft[i].y<<'\n'; 
	for(int i=1;i<=q;i++) {
		int pos1=get_pos(b[i][0]),pos2=get_pos(b[i][1]),len=b[i][0].size();
		if(b[i][0].size()!=b[i][1].size()) ans[i]=0;
		else if(pos1<pos2) qt[++cntb]=(Data){pos2-pos1,pos1,len-pos2-1,i};
		else if(pos2<pos1) qt[++cntb]=(Data){-(pos1-pos2),pos2,len-pos1-1,i};
		else ans[i]=0;
	}
	sort(qt+1,qt+1+cntb);
//	for(int i=1;i<=cntb;i++) cout<<qt[i].w<<" "<<qt[i].x<<" "<<qt[i].y<<'\n'; 
	int jl=1;
//	cout<<cntb<<'\n';
	for(int l=1;l<=cntb;) {
		int r=l;
		while(r<cntb&&qt[r+1].w==qt[l].w) r++;
//		cout<<l<<" "<<r<<'\n';
		while(jl<=n&&ft[jl].w<qt[l].w) jl++;
		if(ft[jl].w>qt[l].w||jl>n) {
			for(int i=l;i<=r;i++) ans[qt[i].id]=0;
			l=r+1;
			continue;
		}
		int jr=jl;
		while(jr<n&&ft[jr+1].w==ft[jl].w) jr++;
//		cout<<jl<<" "<<jr<<'\n';
		int j=jl;
		for(int i=l;i<=r;i++) {
//			cout<<i<<'\n';
			while(j<=jr&&ft[j].x<=qt[i].x) add(ft[j].y+1,1),j++;
//			cout<<i<<'\n';
			ans[qt[i].id]=ask(qt[i].y+1);
		}
		for(int i=jl;i<j;i++) add(ft[i].y+1,-1);
		l=r+1,jl=jr+1;
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}
ll f[MAXX][2];
vector<ll> g[MAXX][2];
int gets(int op,string x,string y) {
	int len=x.size();
	if(op==0) {
		for(int i=0;i<len;i++) {
			if(x[i]!=y[i]) return i;
		}
	}
	for(int i=len-1;i>=0;i--) {
		if(x[i]!=y[i]) return i;
	}
}
int inv[MAXL];
void sol() {
	inv[0]=1;
	for(int i=1;i<MAXL;i++) inv[i]=inv[i-1]*bas%P;
	for(int i=1;i<=n;i++) {
		int len=a[i][0].size();
		ll res=0;
		for(int j=0;j<len;j++) res=(res*bas%P+(ll)(a[i][0][j]-'a'+1))%P;
		f[i][0]=res;
		len=a[i][1].size(),res=0;
		for(int j=0;j<len;j++) res=(res*bas%P+(ll)(a[i][1][j]-'a'+1))%P;
		f[i][1]=res;
	}
//	cout<<a[1][0]<<" "<<f[1][0]<<'\n';
	for(int i=1;i<=q;i++) {
		int len1=b[i][0].size(),len2=b[i][1].size(),Ans=0;
		if(len1!=len2) { cout<<"0\n"; continue; }
//		cout<<"check : "<<i<<'\n';
		ll res=0;
		for(int j=0;j<len1;j++) {
			res=(res*bas%P+(ll)(b[i][0][j]-'a'+1))%P;
			g[i][0].pb(res%P);
		}
//		cout<<"g : "<<b[i][0]<<" "<<g[i][0][len1-1]<<'\n';
		res=0;
		for(int j=0;j<len2;j++) {
			res=(res*bas%P+(ll)(b[i][1][j]-'a'+1))%P;
			g[i][1].pb(res%P);
		}
		int lt=gets(0,b[i][0],b[i][1]),rt=gets(1,b[i][0],b[i][1]),tot=rt-lt+1;
//		cout<<"ltrt : "<<lt<<" "<<rt<<'\n';
		for(int j=1;j<=n;j++) {		//记得改回来 1-> n 
//			cout<<"j = "<<j<<'\n';
			int len=a[j][0].size();
			if(len<tot) continue;
			for(int k=0;k<len;k++) {
//				cout<<"k = "<<k<<'\n';
				int x=k,y=len-(k+tot);
				if(x>lt||k+tot-1>=len) break;
				if(y>(len1-rt-1)) continue;
				int l=lt-x,r=rt+y;
//				cout<<l<<" "<<r<<'\n';
				int fin=g[i][0][r];
				if(l!=0) fin=(fin-g[i][0][l-1]*inv[r-l+1]%P+P)%P;
//				cout<<fin<<' '<<f[j][0]<<'\n'; 
				if(fin!=f[j][0]) continue;
				fin=g[i][1][r];
				if(l!=0) fin=(fin-g[i][1][l-1]*inv[r-l+1]%P+P)%P;
				if(fin==f[j][1]) Ans++;
			}
		}
		cout<<Ans<<'\n';
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
	for(int i=1;i<=q;i++) cin>>b[i][0]>>b[i][1];
	for(int i=1;i<=n;i++) {
		if(!spe(a[i][0])) {	fbt=0; break; }
		if(!spe(a[i][1])) { fbt=0; break; }
	}
	for(int i=1;i<=q;i++) {
		if(!fbt) break;
		if(!spe(b[i][0])) { fbt=0; break; }
		if(!spe(b[i][1])) { fbt=0; break; }
	}
	if(fbt) { solb(); return 0; }
	sol();

	return 0;
}
/*
3 3
aaba abaa
baaa aaba
aaaab abaaa

aaaba aabaa
aabaaa aaaaba
abaaaa aaaaab
*/
