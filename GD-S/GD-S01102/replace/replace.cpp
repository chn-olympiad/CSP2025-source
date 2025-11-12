#include<bits/stdc++.h>
using namespace std;
#define lc (x<<1)
#define rc ((x<<1)|1)
#define mid ((l+r)>>1)
#define ull unsigned long long
const int N=5e6+5,M=2e5+5;
const ull P=998244353;
int n,q,cnt,ans[N];
char s[N],t[N];
map<ull,int>mp;
struct node{int l,r,tp,id;};
vector<node>a[M*2];
bool cmp(node a,node b){
	if(a.l!=b.l)
	return a.l<b.l;
	return a.tp<b.tp;
}
int tr[N<<2],tag[N<<2];
void build(int x,int l,int r){
	if(l==r){
		tr[x]=0;
		tag[x]=-1;
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	tag[x]=-1;
}
void down(int x,int l,int r){
	tr[x]=tag[x]*(r-l+1);
	if(l<r)tag[lc]=tag[rc]=tag[x];
	tag[x]=-1;
}
void modi(int x,int l,int r,int k,int c){
	if(tag[x]!=-1)
	down(x,l,r);
	if(k>r||k<l)return ;
	if(l==r){
		tr[x]+=c;
		return ;
	}
	modi(lc,l,mid,k,c);
	modi(rc,mid+1,r,k,c);
	tr[x]=tr[lc]+tr[rc];
}
void modi1(int x,int l,int r,int L,int R,int c){
	if(tag[x]!=-1)
	down(x,l,r);
	if(l>R||r<L)return ;
	if(l>=L&&r<=R){
		tag[x]=c;
		down(x,l,r);
		return ;
	}
	modi1(lc,l,mid,L,R,c);
	modi1(rc,mid+1,r,L,R,c);
	tr[x]=tr[lc]+tr[rc];
}
int query(int x,int l,int r,int L,int R){
	if(tag[x]!=-1)
	down(x,l,r);
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)return tr[x];
	return query(lc,l,mid,L,R)+query(rc,mid+1,r,L,R);
}
ull hs[M];
int lenn[M],ln[M],rn[M];
int cot[N];
map<ull,int>mp1;
vector<char>ss[M],tt[M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%s%s",s+1,t+1);
		int l=1,r=strlen(s+1),len=r;
		sum+=len;
		while(l<=r&&s[l]==t[l])l++;
		while(r>=l&&s[r]==t[r])r--;
		//printf("haha:%d %d\n",l,r);
		ull u=0;
		for(int j=l;j<=r;j++)u=u*P+(ull)s[j];
		for(int j=l;j<=r;j++)u=u*P+(ull)t[j];
		if(!mp.count(u))
		mp[u]=++cnt;
		int cur=mp[u];
		a[cur].push_back((node){l,len-r+1,1,i});
		ull h=0;
		for(int j=1;j<=len;j++)
		h=h*P+(ull)s[j];
		for(int j=1;j<=len;j++)
		h=h*P+(ull)t[j];
		if(!mp1.count(h))
		mp1[h]=++cnt;
		cur=mp1[h];
		cot[cur]++;
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",s+1,t+1);
		int l=1,r=strlen(s+1),len=r;
		sum+=len;
		lenn[i]=len;
		if(strlen(s+1)!=strlen(t+1)){
			ans[i]=0;
			continue;
		}
		while(l<=r&&s[l]==t[l])l++;
		while(r>=l&&s[r]==t[r])r--;
		//printf("xixi:%d %d\n",l,r);
		if(l>r){
			ans[i]=1;
			continue;
		}
		ull u=0;
		for(int j=l;j<=r;j++)u=u*P+(ull)s[j];
		for(int j=l;j<=r;j++)u=u*P+(ull)t[j];
		if(!mp.count(u))
		mp[u]=++cnt;
		int cur=mp[u];
		a[cur].push_back((node){l,len-r+1,2,i});
		ln[i]=l,rn[i]=r;
		for(int j=1;j<=len;j++)
		ss[i].push_back(s[j]);
		for(int j=1;j<=len;j++)
		tt[i].push_back(t[j]);
	}
	if(sum<=4000){
		for(int pos=1;pos<=q;pos++){
			for(int i=1;i<=ln[pos];i++){
				for(int j=rn[pos];j<=lenn[pos];j++){
					ull u=0;
					for(int k=i;k<=j;k++)
					u=u*P+(ull)ss[pos][k-1];
					for(int k=i;k<=j;k++)
					u=u*P+(ull)tt[pos][k-1];
					if(mp1.count(u))
					ans[pos]+=cot[mp1[u]];
				}
			}
		}
		for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
		return 0;
	}
	build(1,1,N-1);
	for(int i=1;i<=cnt;i++){
		//printf("size:%d\n",a[i].size());
		sort(a[i].begin(),a[i].end(),cmp);
		for(node v:a[i]){
			//printf("l:%d r:%d tp:%d\n",v.l,v.r,v.tp);
			if(v.tp==1)
			modi(1,1,N-1,v.r,1);
			else ans[v.id]=query(1,1,N-1,1,v.r);
		}
		modi1(1,1,N-1,1,N-1,0);
	}
	for(int i=1;i<=q;i++)
	printf("%d\n",ans[i]);
	return 0;
}
