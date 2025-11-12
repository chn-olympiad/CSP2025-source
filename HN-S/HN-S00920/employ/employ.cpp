#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
//#define int long long
//#define int __int128
//#define int unsigned int
#define mod 998244353ll
using namespace std;
void fio(string s,int i){
	freopen((s+(i?to_string(i):"")+".in").c_str(),"r",stdin);
	freopen((s+(i?to_string(i):"")+".out").c_str(),"w",stdout);
}
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}return ret*f;
}
inline void write(int x,int op=0){
	if(x<0){
		putchar('-');
		x=-x;
	}
	stack<char>qwq;
	while(!qwq.empty())qwq.pop();
	while(x>9){
		qwq.push(x%10+'0');
		x/=10;
	}
	qwq.push(x+'0');
	while(!qwq.empty())putchar(qwq.top()),qwq.pop();
	if(op>0)putchar('\n');
	if(op<0)putchar(' ');
}
const int N=514,M=1<<19;
int n,m;
int c[N];
bool s[N];
bool opA=1; 
int fac[N];
void init(){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
}
int f[M][20];
int get(int x){
	int ret=0;
	while(x){
		x^=x&-x;
		ret++;
	}return ret;
}
int ans;
signed main(){
	fio("employ");
	n=read(),m=read();
	init();
	for(int i=1;i<=n;i++)s[i]=getchar()-'0',opA&=s[i];
	for(int i=1;i<=n;i++)c[i]=read();
	if(n<=18){
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			int qwq=get(i);
			for(int j=0;j<=qwq;j++){
				for(int k=1;k<=n;k++){
					if((i>>k-1)&1)continue;
					int to=i|(1<<k-1);
					f[to][j+(bool)(s[qwq+1]&&c[k]>qwq-j)]=(f[to][j+(bool)(s[qwq+1]&&c[k]>qwq-j)]+f[i][j])%mod;
				}
			}
		}
		for(int i=m;i<=n;i++)ans=(ans+f[(1<<n)-1][i])%mod;
		write(ans);
	}else if(opA){
		for(int i=1;i<=n;i++){
			if(!c[i]){
				putchar('0');
				return 0;
			}
		}write(fac[n]);
	}else{
		
	}
	return 0;
}

