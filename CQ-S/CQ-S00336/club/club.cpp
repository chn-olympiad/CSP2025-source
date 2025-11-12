#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rof(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=1e6+5,base=999983,Mod=998244353;
bool SSS;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){f=(ch=='-'?-f:f);ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,a[N];
int b[N],c[N];
int gg[N]; 
bool TTT;
signed main(){
//	printf("%lld Mib\n",(int)(&TTT-&SSS)/1024/1024);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		For(i,1,n) a[i]=read(),b[i]=read(),c[i]=read();
		int ans=0,A=0,B=0,C=0;
		For(i,1,n){
			int mx=max(a[i],max(b[i],c[i]));
			if(mx==a[i]) A++;
			else if(mx==b[i]) B++;
			else if(mx==c[i]) C++;
			ans+=mx;
			
		}if(A<=n/2&&B<=n/2&&C<=n/2){
			printf("%lld\n",ans);
			continue;
		}ans=0;
		if(A>n/2){
			
			For(i,1,n){
				ans+=a[i];
				gg[i]=max(b[i]-a[i],c[i]-a[i]);
			}sort(gg+1,gg+n+1);
			For(i,n/2+1,n) ans+=gg[i];
		}else if(B>n/2){
			For(i,1,n){
				ans+=b[i];
				gg[i]=max(a[i]-b[i],c[i]-b[i]);
			}sort(gg+1,gg+n+1);
			For(i,n/2+1,n) ans+=gg[i];
		}
		else{
			For(i,1,n){
				ans+=c[i];
				gg[i]=max(b[i]-c[i],a[i]-c[i]);
			}sort(gg+1,gg+n+1);
			For(i,n/2+1,n) ans+=gg[i];
			
		}printf("%lld\n",ans);
	}
	return 0;
} 
