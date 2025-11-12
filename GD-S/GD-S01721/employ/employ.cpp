#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+5,mod=998244353;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;
}
int n,m,k,q,sc;
ll ans;
int vis[N],c[N];
char s[N];
void work(int k,int nopas){
	if(n-nopas+n-k+1<m)return;
	if(k>n){
		ans+=(n>=m+nopas);
		return ;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i]=1;
		work(k+1,nopas+(s[k]=='0'||nopas>=c[i]));
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		c[i]=read();
		if(c[i]=='0')sc++;
	}
	if(n-sc<m)return cout<<0,0;
	
	int alls1=1,s0=0;
	for(int i=1;i<=n;i++)if(s[i]=='0')alls1=0,s0++;
	
	if(alls1==1){
		ll ss=1;
		for(int i=1;i<=n;i++)ss=ss*i%mod;
		cout<<ss;
		return 0;
	}
	if(n==m||n-s0<m)return cout<<0,0;
	work(1,0);
	cout<<ans%mod;
	return 0;
}
