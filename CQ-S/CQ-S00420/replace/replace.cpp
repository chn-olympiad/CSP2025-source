#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,SQ=2505,M=5e6+5;
struct HH{
	unsigned long long p,g;
	inline HH operator*(const HH z) const {return {p*z.p,g*z.g};}
	inline HH operator+(const int z) const {return {p+z,g+z};}
	inline HH operator-(const HH z) const {return {p-z.p,g-z.g};}
	inline bool operator<(const HH z) const {return p==z.p?g<z.g:p<z.p;}
	inline bool operator!=(const HH z) const {return p!=z.p||g!=z.g;}
	inline bool operator==(const HH z) const {return p==z.p&&g==z.g;}
}p[M],g[M],h[M];
const HH H={998244353,(int)1e9+7};
struct AA{
	HH a,b;
	int len;
	inline bool operator<(const AA z) const {
		return len==z.len?a<z.a:len<z.len;
	}
}a[N];
map<HH,int> to[N];
struct{
	int len;
	map<HH,int> to;
}b[SQ];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	h[0]={1,1};
	for(int i=1;i<=5e6;i++) h[i]=h[i-1]*H;
	int n,q,cnt=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string c;
		cin>>c,a[i].len=c.size();
		for(int j=0;j<a[i].len;j++) a[i].a=(a[i].a*H)+c[j];
		cin>>c;
		for(int j=0;j<a[i].len;j++) a[i].b=(a[i].b*H)+c[j];
	}
	sort(a+1,a+n+1);
	for(int i=1,k=0;i<=n;i++){
		if(i==1||a[i].a!=a[i-1].a) k++;
		to[k][a[i].b]++;
		if(i==1||a[i].len>a[i-1].len) b[++cnt].len=a[i].len;
		b[cnt].to[a[i].a]=k;
	}
	for(string t1,t2;q--;){
		cin>>t1>>t2;
		const int len=t1.size();
		t1=" "+t1,t2=" "+t2;
		long long ans=0;
		for(int i=1;i<=len;i++) p[i]=p[i-1]*H+t1[i],g[i]=g[i-1]*H+t2[i];
		for(int j=1;j<=cnt;j++)
			for(int i=b[j].len;i<=len&&(p[i-b[j].len]==g[i-b[j].len]);i++) if((p[len]-(p[i]*h[len-i]))==(g[len]-(g[i]*h[len-i]))){
				const HH now=p[i]-(p[i-b[j].len]*h[b[j].len]),ak=g[i]-(g[i-b[j].len]*h[b[j].len]);
				if(b[j].to.count(now)) ans+=to[b[j].to[now]][ak];
			}
		cout<<ans<<"\n";
	}
}
