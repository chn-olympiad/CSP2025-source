#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	char c=getchar();x=0;
	int fh=1;
	while('0'>c||c>'9'){
		if(c=='-') fh*=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') x=x*10-48+c,c=getchar();
	x*=fh;
}
void write(int x){
	if(x<0) {
		putchar('-');
		x*=-1;
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=5e2+5,mod=998244353;
int n,m,flag1,flag2,fac[N],num,c[N],bj[N];
string s;
void dfs(int x,int qm,int cg){
	if(cg>=m) {
		num+=fac[(n-x+1)];
        num%=mod;
		return ;
	}
	if(x==n+1) return ;
	for(int i=1;i<=n;i++){
		if(bj[i]==0){
			bj[i]=x;
			if(c[i]<=qm||s[x]=='0') dfs(x+1,qm+1,cg);
			else dfs(x+1,qm,cg+1);
			bj[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;s=" "+s;
	fac[0]=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		fac[i]=fac[i-1]*i%mod;
		if(c[i]==0) flag1=1;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0') flag2=0;
	}
	if(n==m) {
		if(flag1||flag2) cout<<0;
		else cout<<fac[n]%mod;
		return 0;
	}
	dfs(1,0,0);
	cout<<num;
	return 0;
}