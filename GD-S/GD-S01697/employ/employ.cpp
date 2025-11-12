//By Dream_Flynn(luogu name)
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int k=0;
	bool f=false;
	char c=getchar();
	while(!isdigit(c)){
		f=f||(c=='-');
		c=getchar();
	}
	while(isdigit(c)){
		k=(k<<3)+(k<<1)+(c^48);
		c=getchar();
	}
	return f?-k:k;
}
inline void write(int d,char end_ch='\n'){
	if(d<0){
		d=-d;
		putchar('-');
	}
	int stk[48],top=0;
	do{
		top++;
		stk[top]=d%10;
		d/=10;
	}while(d);
	for(int i=top;i;i--){
		putchar(stk[i]^48);
	}
	if(end_ch!='\0'){
		putchar(end_ch);
	}
}
const int N=514,mod=998244353;
int n,m,ans,c[N],fac[N];
string str;
namespace PlanA{
	bool vis[N];
	void dfs(int d,int sum){
		/*for(int i=1;i<=d;i++){
			cerr<<"  "; 
		}
		cerr<<d<<" "<<sum<<endl;*/
		if(sum>=m){
			ans=(ans+fac[n-d+1])%mod;
			return;
		}
		if(d>=n+1){//cerr<<"P\n";
			/*if(sum>=m){
				ans++;
				ans%=mod;
			}*/
			return;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]){
				continue;
			}
			vis[i]=1;
			int tmp=str[d]-'0';
			if(d-1-sum>=c[i]){
				tmp=0;
			}
			dfs(d+1,sum+tmp);
			vis[i]=0;
		}
	}
	void main(){
		memset(vis,0,sizeof vis);
		dfs(1,0);
		write(ans);
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	m=read();
	cin>>str;
	str=" "+str;
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	if(n<=18){
		PlanA::main();
		return 0;
	}
	return 0;
}

//部分分给的不够多啊(doge) 
//Go home to play Minecraft. 
