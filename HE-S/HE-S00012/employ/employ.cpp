#include<bits/stdc++.h>
#define IL inline
#define mp make_pair
#define pb push_back
#define rpt(a,b,c) for(int a=b;a<=c;a++)
#define tpr(a,b,c) for(int a=b;a>=c;a--)
using namespace std;
typedef long long LL;
const int N=510,mod=998244353;
IL int add(const int &a,const int &b){return a+b>=mod?a+b-mod:a+b;}
IL int mul(const int &a,const int &b){return 1ull*a*b%mod;}
int fac[N],ifac[N],inv[N];
void numinit(const int &n){
	fac[0]=1;rpt(i,1,n)fac[i]=mul(fac[i-1],i);
	inv[1]=1;rpt(i,2,n)inv[i]=mul(mod-mod/i,inv[mod%i]);
	ifac[0]=1;rpt(i,1,n)ifac[i]=mul(ifac[i-1],inv[i]);
}
IL int C(int n,int m){return m>n?0:mul(mul(fac[n],ifac[m]),ifac[n-m]);}

int n,m,c[N];
char t[N];
int s[N],p[N];
bool chk(){
	int cnt=0,pre=0;
	rpt(i,1,n)if(t[i]=='1'){
		if(c[p[i]]>s[i]+pre)cnt++;
		else pre++;
	}
	return cnt>=m;
}
namespace solm1{
	int cnt[N];
	void solve(){
		int ans=fac[n],dt=1,now=0;
		rpt(i,1,n)cnt[c[i]]++;
		rpt(i,1,n)cnt[i]+=cnt[i-1];
		rpt(i,1,n)if(t[i]=='1')dt=mul(dt,max(0,cnt[i-1]-now)),now++;
		dt=mul(dt,fac[n-now]);
		printf("%d",add(ans,mod-dt));
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d%s",&n,&m,t+1);
	numinit(n);
	rpt(i,1,n)s[i]=s[i-1]+(t[i]=='0');
	rpt(i,1,n)scanf("%d",&c[i]),p[i]=i;
	if(m==n){
		int cnt=0;
		rpt(i,1,n)cnt+=!c[i];
		if(cnt||s[n])printf("0");
		else printf("%d",fac[n]);
		return 0;
	}
	if(m==1)return solm1::solve(),0;
	int ans=0;
	do{ans+=chk();}while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
	return 0;
}

