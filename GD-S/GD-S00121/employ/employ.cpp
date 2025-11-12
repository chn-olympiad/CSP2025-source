#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define lowbit(x) (x)&(-x)
using namespace std;
const int N=505;
const int mod=998244353;
int ans;
char ch[N];
int n,m,T,a[N];
inline int read(){
	int s=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return f?-s:s;
}
inline void add(int& x,int y){
	x+=y;
	if(x>=mod) x-=mod;
}
namespace sub1{
	int f[1<<19][19];
	inline void main(){
		f[0][0]=1;
		for(register int i=0;i<(1<<n);++i){
			int t=0;
			for(register int j=0;j<n;++j) t+=(i>>j&1);
			for(register int j=0;j<n;++j){
				if(i>>j&1) continue;
				for(register int k=0;k<=t;++k){
					if(ch[t+1]=='1'&&(t-k)<a[j+1]) add(f[i|(1<<j)][min(k+1,m)],f[i][k]);
					else add(f[i|(1<<j)][k],f[i][k]);
				}
			}
		}
		for(register int i=0;i<(1<<n);++i){
			int t=0;
			for(register int j=0;j<n;++j) t+=(i>>j&1);
		}
		cerr<<f[(1<<n)-1][m]<<"\n";
	}
}
namespace sub2{
	int f[N][N][N];
	inline void main(){
		f[0][0][0]=1;
		
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",ch+1);
	for(register int i=1;i<=n;++i) a[i]=read();
	if(n<=18) sub1::main();
	else{
		ans=1;
		for(register int i=1;i<=n;++i) ans=1ll*ans*i%mod;
		cout<<ans;
//		sub2::main();
	}
	return 0;
}

