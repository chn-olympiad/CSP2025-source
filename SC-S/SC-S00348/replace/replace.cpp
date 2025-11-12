#include<bits/stdc++.h>

using namespace std;
bool Mbe;

using i64=long long;

constexpr int maxL=5e6+10,maxn=2e5+10;

constexpr int bs1=2333,bs2=131,bs3=13331;
constexpr int mo1=1000000007,mo2=998244353,mo3=1000000009;

struct hsnode{
	int a,b,c;
	hsnode(){a=b=c=0;}
	hsnode(int _a,int _b,int _c):a(_a),b(_b),c(_c){}
	hsnode operator+(const int &x){
		return hsnode(((i64)a*bs1%mo1+x)%mo1,((i64)b*bs2%mo2+x)%mo2,((i64)c*bs3%mo3+x)%mo3);
	}
	bool operator<(const hsnode &x)const{
		return a==x.a?b==x.b?c<x.c:b<x.b:a<x.a;
	}
	bool operator==(const hsnode &x)const{
		return a==x.a&&b==x.b&&c==x.c;
	}
};

inline int get(char ch){
	return ch-'a'+1;
}

int n,Q;

char s1[maxL],s2[maxL];
hsnode h1[maxL],h2[maxL];

int tot;
struct node{
	hsnode C,D,pr,sf;
	int Lp,Ls;
}a[maxn];

void work(int id){
	int A=strlen(s1+1);
	
	for(int i=1;i<=A;++i){
		h1[i]=h1[i-1]+get(s1[i]);
		h2[i]=h2[i-1]+get(s2[i]);
	}
	
	if(h1[A]==h2[A]) return;
	
	int L=0,R=A;
	while(L<R){
		int mid=(L+R+1)>>1;
		if(h1[mid]==h2[mid]) L=mid;
		else R=mid-1;
	}
	
	int x=L;
	a[id].Lp=x;a[id].pr=h1[x];
	
	h1[A+1]=hsnode();h2[A+1]=hsnode();
	for(int i=A;i;--i){
		h1[i]=h1[i+1]+get(s1[i]);
		h2[i]=h2[i+1]+get(s2[i]);
	}
//	cerr<<"kkkk"<<'\n';
	L=0,R=A;
	while(L<R){
		int mid=(L+R+1)>>1;
		if(h1[A-mid+1]==h2[A-mid+1]) L=mid;
		else R=mid-1;
	}
//	cerr<<"kkkk"<<'\n';
	int y=L;
	
	a[id].Ls=y;a[id].sf=h1[A-y+1];
	
	h1[x]=hsnode();h2[x]=hsnode();
	for(int i=x+1;i<=A-y;++i){
		h1[i]=h1[i-1]+get(s1[i]);
		h2[i]=h2[i-1]+get(s2[i]);
	}
	
	a[id].C=h1[A-y];a[id].D=h2[A-y];
}

hsnode H1[maxL];

void solve(){
	scanf("%s%s",s1+1,s2+1);
	int A=strlen(s1+1),B=strlen(s2+1);
	
	if(A!=B){
		cout<<"0"<<'\n';return;
	}
	
	for(int i=1;i<=A;++i){
		h1[i]=h1[i-1]+get(s1[i]);
		h2[i]=h2[i-1]+get(s2[i]);
	}
	
	int L=0,R=A;
	while(L<R){
		int mid=(L+R+1)>>1;
		if(h1[mid]==h2[mid]) L=mid;
		else R=mid-1;
	}
//	cerr<<"kkk"<<'\n';
	int x=L;
	
	h1[A+1]=hsnode();h2[A+1]=hsnode();
	for(int i=A;i;--i){
		h1[i]=h1[i+1]+get(s1[i]);
		h2[i]=h2[i+1]+get(s2[i]);
	}
	
	L=0,R=A;
	while(L<R){
		int mid=(L+R+1)>>1;
		if(h1[A-mid+1]==h2[A-mid+1]) L=mid;
		else R=mid-1;
	}
	
	int y=L;
	
	h1[x]=hsnode();h2[x]=hsnode();
	for(int i=x+1;i<=A-y;++i){
		h1[i]=h1[i-1]+get(s1[i]);
		h2[i]=h2[i-1]+get(s2[i]);
	}
	
	hsnode C=h1[A-y],D=h2[A-y];
	
	h1[x+1]=hsnode();
	hsnode pw=hsnode(1,1,1);
	
	for(int i=x;i;--i){
		h1[i]=h1[i+1];
		(h1[i].a+=(i64)get(s1[i])*pw.a%mo1)%=mo1;
		(h1[i].b+=(i64)get(s1[i])*pw.b%mo2)%=mo2;
		(h1[i].c+=(i64)get(s1[i])*pw.c%mo3)%=mo3;
		
		pw.a=(i64)pw.a*bs1%mo1;
		pw.b=(i64)pw.b*bs2%mo2;
		pw.c=(i64)pw.c*bs3%mo3;
	}
	
	H1[A-y]=hsnode();
	pw=hsnode(1,1,1);
	
	for(int i=A-y+1;i<=A;++i){
		H1[i]=H1[i-1];
		(H1[i].a+=(i64)get(s1[i])*pw.a%mo1)%=mo1;
		(H1[i].b+=(i64)get(s1[i])*pw.b%mo2)%=mo2;
		(H1[i].c+=(i64)get(s1[i])*pw.c%mo3)%=mo3;
		
		pw.a=(i64)pw.a*bs1%mo1;
		pw.b=(i64)pw.b*bs2%mo2;
		pw.c=(i64)pw.c*bs3%mo3;		
	}
	
	int ans=0;
	for(int i=1;i<=tot;++i){
		if(a[i].Lp<=x&&a[i].Ls<=y&&a[i].pr==h1[x-a[i].Lp+1]&&a[i].sf==H1[A-y+a[i].Ls]&&a[i].C==C&&a[i].D==D) ans++;
	}
	
	cout<<ans<<'\n';
}

bool Med;
int main(){
//	ios::sync_with_stdio(false);cin.tie(0);
	
//	freopen("replace1.in","r",stdin);
//	freopen("replacemy.out","w",stdout);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&Q);
	
	for(int i=1;i<=n;++i){
		scanf("%s%s",s1+1,s2+1);
		work(++tot);
	}
//	cerr<<"complete init"<<'\n';
	while(Q--) solve();
	
	cerr<<'\n'<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
	cerr<<'\n'<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}