#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn=5e6+7,mod=2499997;

int n,q,maxlen;
ull maxa,maxb;
ull prea[maxn>>1],preb[maxn>>1],b131[maxn>>1];
struct stu{
	ull hha,hhb;
	int lea,leb;
};
vector<stu>g;
bool cla[maxn];
vector<pair<int,int> >hsa[maxn>>1],hsb[maxn>>1];

int in(){
	int t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		t=(t<<3)+(t<<1)+(c^48);
		c=getchar();
	}
	return t*f;
}

void out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x^48);
	else out(x/10),putchar(x%10^48);
}

void inserta(ull x,int lent){
	int ha=x%mod;
	hsa[ha].push_back(make_pair(x,lent));
}

void insertb(ull x,int lent){
	int ha=x%mod;
	hsb[ha].push_back(make_pair(x,lent));
}

int finda(ull x){
	int ha=x%mod;
	for(pair<int,int> u:hsa[ha]){
		if(u.first==x) return u.second;
	}
	return -1;
}

int findb(ull x){
	int ha=x%mod;
	for(pair<int,int> u:hsb[ha]){
		if(u.first==x) return u.second;
	}
	return -1;
}

void cle(){
	for(int i=0;i<mod;i++){
		if(cla[i]){
			cla[i]=0;
			hsa[i].clear();
			hsb[i].clear();
		}
	}
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=in(),q=in();
	ull t=0;
	int len=0;
	for(int i=1;i<=n;i++){
		stu cur;
		char c;
		c=getchar();
		t=0;
		len=0;
		while(c!=' '){
			t=(t*131)+(c-'a');
			len++;
			c=getchar();
		}
		if(maxlen<=len){
			maxlen=len,maxa=t;
		}
		cur.hha=t,cur.lea=len;
		c=getchar();
		len=0;
		t=0;
		while(c!='\n'&&c!='\r'){
			t=(t*131)+(c-'a');
			len++;
			c=getchar();
		}
		if(maxlen==len) maxb=t;
		cur.hhb=t,cur.leb=len;
		g.emplace_back(cur);
	}
	b131[0]=1;
	for(int i=1;i<=(maxn>>1);i++) b131[i]=b131[i-1]*131;
	while(q--){
		int ans=0;
		char c;
		c=getchar();
		int ft=0,ed=0;
		int lena=0,lenb=0;
		while(c!=' '){
			lena++;
			prea[lena]=prea[lena-1]*131+(c-'a');
			inserta(prea[lena],lena);
			c=getchar();
		}
		c=getchar();
		bool flag=1;
		while(c!='\n'&&c!='\r'){
			lenb++;
			if(flag&&(c-'a')==prea[lenb]%131) ft++;
			if((c-'a')!=prea[lenb]%131) ed=lenb,flag=0;
			preb[lenb]=preb[lenb-1]*131+(c-'a');
			insertb(preb[lenb],lenb);
			c=getchar();
		}
		int fi=0;
		for(int i=0;i<=lena;i++){
			for(stu u:g){
				int ga=finda(prea[i]*b131[u.lea]+u.hha);
				int gb=findb(preb[i]*b131[u.leb]+u.hhb);
				if(ga==-1||gb==-1) continue;
				if(ga==gb&&i<=ft&&ga>=ed){
					ans++;
				}
			}
		}
		if(maxa==prea[lena]&&maxb==preb[lenb]) ans++;
		out(ans),putchar('\n');
		for(int i=1;i<=lena;i++) prea[i]=preb[i]=0;
		lena=0,lenb=0,ft=1,ed=1;
		flag=1;
		cle();
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/