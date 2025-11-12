#define x first
#define y second
#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstring>
using namespace std;
const int st1=17,st2=29,mod1=998244341,mod2=998244353,N=200010,M=5000010;
typedef long long LL;
typedef pair<int,int> PII;
char ch1[M],ch2[M];
bool st[N];
struct Shash{
	PII h1,h2,h3;
	int id;
	bool operator<(const Shash &W)const{
		if(h1!=W.h1)
			return h1<W.h1;
		if(h2!=W.h2)
			return h2<W.h2;
		if(h3!=W.h3)
			return h3<W.h3;
		return id<W.id;
	}
}hs1[N],hs2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		scanf("%s%s",ch1+1,ch2+1);
		int l=M,r=0,len=strlen(ch1+1);
		for(int i=1;i<=len;++i)
			if(ch1[i]!=ch2[i]){
				l=min(l,i);
				r=max(r,i);
			}
		if(l==M)
			l=1,r=len;
		//printf("%d %d\n",l,r);
		PII nh1={0,0},nh2={0,0},nh3={0,0},nh4={0,0};
		for(int j=l;j<=r;++j){
			nh1.x=((LL)nh1.x*st1+ch1[j])%mod1;
			nh1.y=((LL)nh1.y*st2+ch1[j])%mod2;
			nh2.x=((LL)nh2.x*st1+ch2[j])%mod1;
			nh2.y=((LL)nh2.y*st2+ch2[j])%mod2;
		}
		for(int j=l-1;j;--j){
			nh3.x=((LL)nh3.x*st1+ch1[j])%mod1;
			nh3.y=((LL)nh3.y*st2+ch1[j])%mod2;
		}
		for(int j=r+1;j<=len;++j){
			nh4.x=((LL)nh4.x*st1+ch1[j])%mod1;
			nh4.y=((LL)nh4.y*st2+ch1[j])%mod2;
		}
		hs1[i]={nh1,nh2,nh3,i};
		hs2[i]={nh1,nh2,nh4,i};
	}
	sort(hs1+1,hs1+1+n);
	sort(hs2+1,hs2+1+n);
	/*for(int i=1;i<=n;++i)
		printf("%d ",hs1[i].id);
	puts("");
	for(int i=1;i<=n;++i)
		printf("%d ",hs2[i].id);
	puts("");*/
	for(int i=1;i<=q;++i){
		scanf("%s%s",ch1+1,ch2+1);
		int l=M,r=0,len=strlen(ch1+1),res=0;
		for(int i=1;i<=len;++i)
			if(ch1[i]!=ch2[i]){
				l=min(l,i);
				r=max(r,i);
			}
		PII nh1={0,0},nh2={0,0},nh3={0,0};
		for(int j=l;j<=r;++j){
			nh1.x=((LL)nh1.x*st1+ch1[j])%mod1;
			nh1.y=((LL)nh1.y*st2+ch1[j])%mod2;
			nh2.x=((LL)nh2.x*st1+ch2[j])%mod1;
			nh2.y=((LL)nh2.y*st2+ch2[j])%mod2;
		}
		int l1=lower_bound(hs1+1,hs1+1+n,Shash{nh1,nh2})-hs1;
		int r1=lower_bound(hs1+1,hs1+1+n,Shash{nh1,nh2,{mod1,mod2}})-hs1-1;
		//printf("%d %d\n",l1,r1);
		for(int j=l-1;~j;--j){
			nh3.x=((LL)nh3.x*st1+ch1[j])%mod1;
			nh3.y=((LL)nh3.y*st2+ch1[j])%mod2;
			int l2=lower_bound(hs1+1+l1,hs1+1+r1,Shash{nh1,nh2})-hs1;
			int r2=lower_bound(hs1+1+l1,hs1+1+r1,Shash{nh1,nh2,{mod1,mod2}})-hs1-1;
			for(int k=l2;k<=r2;++k)
				st[hs1[k].id]=1;
		}
		nh3={0,0};
		for(int j=r+1;j<=len+1;++j){
			int l2=lower_bound(hs2+1+l1,hs2+1+r1,Shash{nh1,nh2})-hs2;
			int r2=lower_bound(hs2+1+l1,hs2+1+r1,Shash{nh1,nh2,{mod1,mod2}})-hs2-1;
			for(int k=l2;k<=r2;++k)
				if(st[hs2[k].id])
					++res;
			nh3.x=((LL)nh3.x*st1+ch1[j])%mod1;
			nh3.y=((LL)nh3.y*st2+ch1[j])%mod2;
		}
		nh3={0,0};
		for(int j=l-1;~j;--j){
			int l2=lower_bound(hs1+1+l1,hs1+1+r1,Shash{nh1,nh2})-hs1;
			int r2=lower_bound(hs1+1+l1,hs1+1+r1,Shash{nh1,nh2,{mod1,mod2}})-hs1-1;
			for(int k=l2;k<=r2;++k)
				st[hs1[k].id]=0;
			nh3.x=((LL)nh3.x*st1+ch1[j])%mod1;
			nh3.y=((LL)nh3.y*st2+ch1[j])%mod2;
		}
		printf("%d\n",res);
	}
	return 0;
}