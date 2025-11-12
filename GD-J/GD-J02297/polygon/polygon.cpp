//ccf orz
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return f*x;
} 
const int mod=998244353;
const int N=5e4+10;
int n,a[N],ans;
bool used[1<<(22)];//40tps
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=7;i<(1<<(n+1));i++){
		int ii=i,s=0,m=0,c=0,x=1;
		while(ii>0&&x<=n){
			if(ii&1){
				c++;
				s+=a[x];
				m=max(m,a[x]);
			}
			ii>>=1;
			x++;
		}
		if(c<3) continue;
		if(s>2*m) ans=(ans+1)%mod;
	}
	cout<<ans/2;
	return 0;
}
