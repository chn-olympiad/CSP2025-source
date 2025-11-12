#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&-x)
using namespace std;
namespace FastIO{
	template<class T>
	T read(T&x){
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f|=!(ch^'-'),ch=getchar();
		while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch&0xF),ch=getchar();
		x=(f?-x:x);return x;
	}template<class T>
	void write(T x,char ch=' '){
		if(x<0) putchar('-'),x=-x;
		char tmp[41];int cnt=0;
		while(x>9) tmp[cnt++]=x%10+'0',x/=10;tmp[cnt++]=x+'0';
		while(cnt) putchar(tmp[--cnt]);putchar(ch);
	}
};
using namespace FastIO;
const int N=5e6+10,M=2e5+10,base=23333,INF=0x3f3f3f3f;
struct node{int b,l,r;}l[M];
struct question{int b,l,r,id;}q[M];
struct fenwick_tree{
	int tr[N],n;
	inline void resize(int x){n=x;}
	inline void update(int x,int val){for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=val;}
	int query(int x){int res=0;for(int i=x;i;i-=lowbit(i)) res+=tr[i];return res;}
}BIT;
int n,m,cnt;
ull H[N],HH[N],pw[N];
char s[N],t1[N],t2[N];
unordered_map<ull,int>mp;
ll ans[N];
inline ull get(int l,int r){return H[r]-H[l-1]*pw[r-l+1];}
inline ull gett(int l,int r){return HH[r]-HH[l-1]*pw[r-l+1];}
inline bool cmp1(node x,node y){
	if(x.b^y.b) return x.b<y.b;
	if(x.l^y.l) return x.l<y.l;
	return x.r<y.r;
}
inline bool cmp2(question x,question y){
	if(x.b^y.b) return x.b<y.b;
	if(x.l^y.l) return x.l<y.l;
	return x.r<y.r;
}
void solve(){
	sort(q+1,q+cnt+1,cmp2);
	int s=1,lim=s,r=s;
	BIT.resize(N-10);
	for(int i=1;i<=cnt;i++){
		if(q[i].b!=l[s].b){
			for(int j=s;j<r;j++) BIT.update(l[j].r+1,-1);
			s=lim;
			while(s<=n&&l[s].b<q[i].b) s++;
			if(s>n) return;
			lim=s+1;
			if(l[s].b!=q[i].b) continue;
			while(lim<=n&&l[lim].b==l[s].b) lim++;
			r=s;
		}
		while(r<lim&&l[r].l<=q[i].l) BIT.update(l[r].r+1,1),r++;
		ans[q[i].id]=BIT.query(q[i].r+1);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n),read(m);
	pw[0]=1;
	for(int i=1;i<=N-10;i++) pw[i]=pw[i-1]*base;
	bool A=true;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1),p=0;
		int sumb=0;ull h=0;
		for(int j=1;j<=len;j++){
			h=h*base+s[j];
			if(s[j]=='b') p=j,sumb++;
			else if(s[j]!='a') A=false;
		}
		if(sumb!=1) A=false;
		scanf("%s",s+1);
		int pp=0;
		sumb=0;
		for(int j=1;j<=len;j++){
			h=h*base+s[j];
			if(s[j]=='b') pp=j,sumb++;
			else if(s[j]!='a') A=false;
		}
		if(sumb!=1) A=false;
		mp[h]++;
	}
	for(int id=1;id<=m;id++){
		bool flag=true;int sumb=0,p=0,pp=0;
		scanf("%s",t1+1);
		int len=strlen(t1+1);
		for(int i=1;i<=len;i++){
			H[i]=H[i-1]*base+t1[i];
			if(t1[i]=='b') p=i,sumb++;
			else if(t1[i]!='a') A=false;
		}
		if(sumb!=1) flag=false;
		scanf("%s",t2+1);
		sumb=0;
		for(int i=1;i<=len;i++){
			HH[i]=HH[i-1]*base+t2[i];
			if(t2[i]=='b') pp=i,sumb++;
			else if(t2[i]!='a') A=false;
		}
		if(sumb!=1) flag=false;
	//	if(A&&flag){q[++cnt]={pp-p,p-1,n-pp};continue;}
		for(int i=1;i<=len;i++){
			if(i>1&&t1[i-1]!=t2[i-1]) break;
			for(int j=len;j>=i;j--){
				if(j<len&&t1[j+1]!=t2[j+1]) break;
				ull now=get(i,j)*pw[j-i+1]+gett(i,j);
				if(mp.count(now)) ans[id]+=mp[now];
			}
		}
	}
	if(cnt) solve();
	for(int i=1;i<=m;i++) write(ans[i],'\n');
	fclose(stdin);fclose(stdout);
	return 0;
}
