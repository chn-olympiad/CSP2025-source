#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+20;
const int mod=998244353;
inline int read(){
	int f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return f*k;
}
int n,m;
int s[N];
int c[N];
string str;
int pre[N];
int vis[11];
int fac[N];
int num;
int ans=0;
inline void dfs(int step,int k){
	if(step==n+1){
		if(k>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int tmp=step-1-k;
			if(tmp<c[i]){
				if(s[step]==1) dfs(step+1,k+1);
				else dfs(step+1,k);
			}else dfs(step+1,k);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>str;
	str=' '+str;
	for(int i=1;i<=n;i++){
		s[i]=str[i]-'0';
		pre[i]=pre[i-1]+(s[i]==0);
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
		if(c[i]==0) num++;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	if(n<=10){
		int cnt=0;
		dfs(1,0);
		cout<<ans<<endl;
	}else if(n==m){
		if(pre[n]==0&&num==0) cout<<fac[n]%mod<<endl;
		else cout<<0<<endl;
	}else if(m==1){
		if(pre[n]==n) cout<<0<<endl;
		else if(num==n) cout<<0<<endl;
		else{
			
		}
	}else if(pre[n]==0){
		if(n-num<m){
			cout<<0;
			return 0;
		}
		int res=0;
		sort(c+1,c+n+1);
		for(int i=num+1;i<=n;i++){
			
		}
		cout<<fac[num]*res%mod<<endl;
	}
	
	
	return 0;
}
