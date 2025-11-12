#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define lowbit(x) (x)&(-x)
using namespace std;
const int N=2e5+10;
const int M=5e6+10;
const int base=29;
const int mod=998244353;
struct node{
	ll x,y,l,r,id;
}a[N];
int ans;
char s[N],t[N];
int hs[M],ht[M],pw[M];
string sr[N];
int n,m,T,bel[N],pl,pr,L[N],R[N];
inline int read(){
	int s=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return f?-s:s;
}
inline ll gs(int l,int r){
	if(l>r) return 0;
	return (hs[r]-1ll*hs[l-1]*pw[r-l+1]%mod+mod)%mod;
}
inline ll gt(int l,int r){
	if(l>r) return 0;
	return (ht[r]-1ll*ht[l-1]*pw[r-l+1]%mod+mod)%mod;
}
inline node work(){
	m=strlen(s+1);
	for(register int i=1;i<=m;++i) hs[i]=(1ll*hs[i-1]*base+s[i])%mod;
	for(register int i=1;i<=m;++i) ht[i]=(1ll*ht[i-1]*base+t[i])%mod;
	int l=1,r=m;
	while(l<=n&&s[l]==t[l]) ++l;
	while(r>=1&&s[r]==t[r]) --r;
	pl=l,pr=r;
	if(l>r) return {-1,-1,-1,-1,0};
	else return {gs(l,r),gt(l,r),gs(1,l-1),gs(r+1,m),0};
}
inline bool cmp(node x,node y){
	if(x.x!=y.x) return x.x<y.x;
	if(x.y!=y.y) return x.y<y.y;
	if(x.l!=y.l) return x.l<y.l;
	return x.r<y.r;
}
inline int fnd(node res){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid].x<res.x||(a[mid].x==res.x&&a[mid].y<res.y)||(a[mid].x==res.x&&a[mid].y==res.y&&a[mid].l<res.l)) l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),T=read();
	pw[0]=1;
	for(register int i=1;i<M;++i) pw[i]=1ll*pw[i-1]*base%mod;
	for(register int i=1;i<=n;++i){
		scanf("%s %s",s+1,t+1);
		a[i]=work();a[i].id=i;
		if(pl<=pr){
			for(register int j=pr+1;j<=m;++j) sr[i]+=s[j];
		}
	}
	sort(a+1,a+n+1,cmp);
	int blk=0;
	for(register int i=1;i<=n;){
		int j=i;
		while(j<n&&a[j+1].x==a[j].x&&a[j+1].y==a[j].y&&a[j].l==a[j+1].l) ++j;
		++blk;L[blk]=i,R[blk]=j;
		while(i<=j){
			bel[i]=blk;
			++i;
		}
	}
	map<int,int> mp;
	for(register int tt=1;tt<=T;++tt){
		scanf("%s %s",s+1,t+1);
		if(strlen(s+1)!=strlen(t+1)){
			cout<<"0\n";
			continue;
		}
		node res=work();
		mp.clear();
		for(register int i=pr;i<=m;++i) mp[gs(pr+1,i)]=1;
		int id=fnd({res.x,res.y,0,0});
		if(a[id].x!=res.x||a[id].y!=res.y){
			cout<<"0\n";
			continue;
		}
		ans=0;
		for(register int i=pl;i>=1;--i){
			ll nl=gs(i,pl-1);
			int idx=fnd((node){res.x,res.y,nl,0});
			if(a[idx].x!=res.x||a[idx].y!=res.y||a[idx].l!=nl) continue;
			int tot=0,pid=bel[idx];
			for(register int j=L[pid];j<=R[pid];++j) if(mp[a[j].r]) ++tot;
			ans+=tot;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
