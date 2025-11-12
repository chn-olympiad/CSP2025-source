#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define mk make_pair
#define N 5000009
#define M 5000009
#define ull unsigned long long
using namespace std;
inline char nc(){static char buf[1<<20],*p=buf,*q=buf;return p==q&&(q=(p=buf)+fread(buf,1,1<<20,stdin),p==q)?EOF:*p++;}
inline ll rd(){bool f=0;char ch=nc();while(ch<'0'||ch>'9')f|=(ch=='-'),ch=nc();ll ans=0;while(ch>='0'&&ch<='9')ans=ans*10+ch-'0',ch=nc();return f?-ans:ans;}
char buf[1<<20],*p3=buf;inline void pc(char c){p3-buf<=1<<20?*p3++=c:(fwrite(buf,1,p3-buf,stdout),p3=buf,*p3++=c);}
inline void wt(ll x){if(x<0)x=-x,pc('-');if(x>9)wt(x/10);pc(x%10+'0');}
const ull bs=13331;
int n,q,len[N],lth[N][2];
vector<char>s[N][2],c[N][2];
ull g[N];
map<pair<ull,ull>,int>mp;
map<ull,int>mq[N],id[N];
vector<int>V[N],E[N];int idx,idt;
int rt[N],cnt,tr[N][26],pts[N];
char a[2][M];
void dfs(int t,int u,ull val){
	id[t][val]=u;
	for(int i=0;i<26;i++){
		int v=tr[u][i];
		if(!v)continue;
		pts[v]+=pts[u],dfs(t,v,val*bs+i+'a');
	}
}
ull f[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace3.in","r",stdin);
//	freopen("Mikoto.txt","w",stdout);
	n=rd(),q=rd();
	for(int i=1;i<=n;i++){
		char ch=nc();
		while(ch<'a'||ch>'z')ch=nc();
		s[i][0].eb(0),s[i][1].eb(0);
		while(ch>='a'&&ch<='z')len[i]++,s[i][0].eb(ch),ch=nc();
		while(ch<'a'||ch>'z')ch=nc();
		while(ch>='a'&&ch<='z')s[i][1].eb(ch),ch=nc();
		int l=1,r=len[i];
		while(l<=n&&s[i][0][l]==s[i][1][l])l++;
		while(r>=1&&s[i][0][r]==s[i][1][r])r--;
		if(l==n+1)continue;
		ull v[2]={0,0};
		for(int j=l;j<=r;j++)v[0]=v[0]*bs+s[i][0][j],v[1]=v[1]*bs+s[i][1][j];
		if(!mp[mk(v[0],v[1])])mp[mk(v[0],v[1])]=++idx;
		V[mp[mk(v[0],v[1])]].eb(i);
		lth[i][0]=l-1,lth[i][1]=len[i]-r,c[i][0].eb(0),c[i][1].eb(0);
		for(int j=l-1;j;j--)c[i][0].eb(s[i][0][j]);for(int j=r+1;j<=len[i];j++)c[i][1].eb(s[i][1][j]);
		g[i]=0;for(int j=1;j<=lth[i][1];j++)g[i]=g[i]*bs+c[i][1][j];
	}
	for(int t=1;t<=idx;t++){
		for(int i=0;i<(int)V[t].size();i++){
			int x=V[t][i];
			if(!mq[t][g[x]])mq[t][g[x]]=++idt;
			E[mq[t][g[x]]].eb(x);
		}
	}
	for(int t=1;t<=idt;t++){
		rt[t]=++cnt;
		for(int i=0;i<(int)E[t].size();i++){
			int x=E[t][i];
			int u=rt[t];
			for(int j=1;j<=lth[x][0];j++){
				int o=c[x][0][j]-'a';
				if(!tr[u][o])tr[u][o]=++cnt;
				u=tr[u][o];
			}
			pts[u]++;
		}
		dfs(t,rt[t],0);
	}
	for(int i=1;i<=q;i++){
		int lt[2]={0,0};
		char ch=nc();
		while(ch<'a'||ch>'z')ch=nc();
		while(ch>='a'&&ch<='z')a[0][++lt[0]]=ch,ch=nc();
		while(ch<'a'||ch>'z')ch=nc();
		while(ch>='a'&&ch<='z')a[1][++lt[1]]=ch,ch=nc();
		if(lt[0]!=lt[1]){wt(0),pc('\n');continue;}
		int l=1,r=lt[0];
		while(a[0][l]==a[1][l])l++;
		while(a[0][r]==a[1][r])r--;
		ull res[2]={0,0};for(int j=l;j<=r;j++)res[0]=res[0]*bs+a[0][j],res[1]=res[1]*bs+a[1][j];
		int t=mp[mk(res[0],res[1])];
		if(!t){wt(0),pc('\n');continue;}
		f[l]=0;for(int j=l-1;j;j--)f[j]=f[j+1]*bs+a[0][j];
		int ans=0;ull sum=0;
		if(E[mq[t][sum]].size()){
			int o=mq[t][sum];
			int L=1,R=l;
			while(L<R){
				int mid=(L+R)>>1;
				if(id[o].find(f[mid])!=id[o].end())R=mid;
				else L=mid+1;
			}
			ans+=pts[id[o][f[L]]];
		}
		for(int j=r+1;j<=lt[0];j++){
			sum=sum*bs+a[0][j];
			if(E[mq[t][sum]].size()){
				int o=mq[t][sum];
				int L=1,R=l;
				while(L<R){
					int mid=(L+R)>>1;
					if(id[o].find(f[mid])!=id[o].end())R=mid;
					else L=mid+1;
				}
				ans+=pts[id[o][f[L]]];
			}
		}
		wt(ans),pc('\n');
	}
	fwrite(buf,1,p3-buf,stdout);
	return 0;
}
