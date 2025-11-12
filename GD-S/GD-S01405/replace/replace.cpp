#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define ll long long
#define wc unsigned short
using namespace std;
namespace lch{
char __;
inline constexpr wc make(char x,char y){ return (wc)x<<8|y; }
const int N=2e5+10,L=2.5e6+10;
int n,m;
string a[N][2];
unordered_map<wc,int> ch[L];
// __gnu_pbds::cc_hash_table<wc,int> ch[L];
int fail[L],len[L],ed[L],sum[L];
int up[L][23];
int nc=0;
void insert(const string& x,const string& y){
	assert(x.size()==y.size());
	int now=0;
	for(int i=0;i<x.size();i++) {
		int& nxt=ch[now][make(x[i],y[i])];
		if(!nxt) {
			nxt=++nc; len[nxt]=len[now]+1;
		}
		now=nxt;
	}
	ed[now]++;
}
void build_ac(){
	queue<int> q;
	for(auto [c,v]:ch[0]) q.push(v);
	while(!q.empty()){
		int u=q.front(); q.pop();
		up[u][0]=fail[u];
		sum[u]=sum[fail[u]]+ed[u];
		for(int i=1,lst=fail[u];i<=22;i++) lst=up[u][i]=up[lst][i-1];
		for(auto [c,v]:ch[u]){
			int f=fail[u];
			while(f&&ch[f].find(c)==ch[f].end()) f=fail[f];
			auto it=ch[f].find(c);
			if(it!=ch[f].end()) fail[v]=it->second;
			q.push(v);
		}
	}
}
char ___;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
		insert(a[i][0],a[i][1]);
	}
	build_ac();
//	cerr<<nc<<endl;
//	return 0;
//	int cc=0;
	while(m--){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			puts("0");
			continue;
		}
		assert(x!=y);
		int k=x.size()-1;
		int fir=0,lst=k;
		while(x[fir]==y[fir]) fir++;
		while(x[lst]==y[lst]) lst--;
//		printf("%d %d\n",fir,lst);
		int now=0;
		ll ans=0;
		for(int i=0;i<=k;i++){
			wc c=make(x[i],y[i]);
			while(now&&ch[now].find(c)==ch[now].end()) now=fail[now];
			auto it=ch[now].find(c);
			if(it==ch[now].end()) now=0;
			else now=it->second;
			if(i>=lst){
//				++cc;
				int f=now;
				int reqlen=i-fir+1; // >= this
				if(len[now]<reqlen) continue;
				for(int i=22;i>=0;i--) if(len[up[f][i]]>=reqlen) f=up[f][i];
				f=fail[f];
//				printf("%d %d %d %d\n",now,f,t[now].sum,t[f].sum);
				ans+=sum[now]-sum[f];
			}
		}
		cout<<ans<<'\n';
	}
//	cerr<<cc<<endl;
	return 0;
}
}
int main(){
#ifndef LCH
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
#endif
	cerr<<"Memo: "<<abs(&lch::___-&lch::__)/1048576.<<"MB\n";
	auto st=clock();
	int r=lch::main();
	cerr<<"Time: "<<clock()-st<<"ms\n";
	return r;
}

