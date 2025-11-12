#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<unordered_map>
#include<vector>
#define gc()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define FIN(x) freopen(x".in","r",stdin);
#define FOUT(x) freopen(x".out","w",stdout);
#define ll long long
#define il inline
#define re register int
#define rl register ll
using namespace std;
const ll MN=1e7+5,N=5e6,base=1e5+43,mod=1e9+43;
ll n,q,h1[MN+5],h2[MN+5],pw[MN+5];
bool vis[N+5];
unordered_map<ll,ll> t;
vector<ll> p,a[MN];
char buf[1<<23],*p1=buf,*p2=buf,s1[N+5],s2[N+5];
il ll read(){ll x=0,f=1;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}return x*f;}
il void write(rl x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
il ll gs1(rl l, rl r){return r<l?0:(h1[r]-h1[l-1]*pw[r-l+1]%mod+mod)%mod;}
il ll gs2(rl l, rl r){return r<l?0:(h2[r]-h2[l-1]*pw[r-l+1]%mod+mod)%mod;}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	if(n<=100){pw[0]=1;for(re i=1; i<=N; ++i) pw[i]=pw[i-1]*base%mod;for(re i=1; i<=n; ++i){ll l1,l2,h1=0,h2=0;cin>>s1>>s2;l1=strlen(s1);l2=strlen(s2);for(re j=0; j<l1; ++j) h1=(h1*base+s1[j])%mod;for(re j=0; j<l2; ++j) h2=(h2*base+s2[j])%mod;t[h1]=h2;if(!vis[l1])vis[l1]=1,p.push_back(l1);}sort(p.begin(),p.end());while(q--){ll l1,l2,ans=0;cin>>s1+1>>s2+1;l1=strlen(s1+1);l2=strlen(s2+1);if(l1!=l2){write(0);putchar('\n');continue;}for(re i=1; i<=l1; ++i) h1[i]=(h1[i-1]*base+s1[i])%mod;for(re i=1; i<=l2; ++i) h2[i]=(h2[i-1]*base+s2[i])%mod;for(re i=1; i<=l1; ++i) for(auto x:p) if(x<=i){if(t[gs1(x-i+1,i)]==gs2(x-i+1,i)&&gs1(1,x-i+1)==gs2(1,x-i+1)&&gs1(i+1,l1)==gs2(i+1,l2)) ++ans;}else break;write(ans);putchar('\n');}return 0;}
	for(re i=1; i<=n; ++i){
		ll n1,n2,l1,l2;
		cin>>s1>>s2;
		l1=strlen(s1);l2=strlen(s2);
		for(re j=0; j<l1; ++j) if(s1[j]=='b'){n1=j;break;}
		for(re j=0; j<l2; ++j) if(s2[j]=='b'){n2=j;break;}
		a[n2-n1+N].push_back(n1);
	}
	while(q--){
		ll n1,n2,l1,l2;
		cin>>s1>>s2;
		l1=strlen(s1);l2=strlen(s2);
		if(l1!=l2){write(0);putchar('\n');continue;}
		for(re j=0; j<l1; ++j) if(s1[j]=='b'){n1=j;break;}
		for(re j=0; j<l2; ++j) if(s2[j]=='b'){n2=j;break;}
		ll x=lower_bound(a[n2-n1+N].begin(),a[n2-n1+N].end(),n1+1)-a[n2-n1+N].begin();
		write(x);putchar('\n');
	}
	return 0;
}//251101 CSP2025 RP++
