#include<bits/stdc++.h>
#define int long long
#define qwe(i,l,r) for(int i=l;i<=r;++i)
#define ewq(i,l,r) for(int i=l;i>=r;--i)
#define mkp make_pair
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f=ch=='-'?-f:f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
int Max(int a,int b){
	return a>b?a:b;
}
int Min(int a,int b){
	return a<b?a:b;
}
const int N=1e5+5;
int n,a[N],b[N],c[N];
int f[N][3];
int A[N],B[N],C[N];
void solve(){
	n=read();
	int ans=0,topa=0,topb=0,topc=0;
	qwe(i,1,n){
		a[i]=read();b[i]=read();c[i]=read();
		if(a[i]>=b[i]&&a[i]>=c[i])ans+=a[i],A[++topa]=a[i]-Max(b[i],c[i]);
		else if(b[i]>=c[i])ans+=b[i],B[++topb]=b[i]-Max(a[i],c[i]);
		else ans+=c[i],C[++topc]=c[i]-Max(b[i],a[i]);
//		cout<<ans<<'\n';
	}
	int op=1;
	if(topa>n/2){
//		puts("pass");
		sort(A+1,A+topa+1);
		while(topa>n/2){
			ans-=A[op++];
			--topa;
		}
	}
	if(topb>n/2){
		sort(B+1,B+topb+1);
		while(topb>n/2){
			ans-=B[op++];
			--topb;
		}
	}
	if(topc>n/2){
		sort(C+1,C+topc+1);
		while(topc>n/2){
			ans-=C[op++];
			--topc;
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--)solve();
	return 0;
}
//freopen("")
//I love Furina
//stO fishPJ Orz

