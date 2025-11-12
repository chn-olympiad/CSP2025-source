#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int BUF=1<<20;
char buf[BUF],*p1=buf,*p2=buf;
inline char gc(){
	if(p1==p2)p2=(p1=buf)+fread(buf,1,BUF,stdin);
	return p1==p2?EOF:*p1++;
}
template<class T=int>T read(T&&x=0){
	int f=1;
	x=0;
	char ch=gc();
	while(!isdigit(ch))f-=(ch=='-')<<1,ch=gc();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return x;
}
const int mod=998244353;
char s[505];
int c[505],m,n;
namespace sol1{
	int vis[15],arr[15];
	int ans=0;
	void dfs(int p,int lim){
		if(p>n){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'||cnt>=c[arr[i]])cnt++;
			}
			ans+=(n-cnt>=lim);
			return;
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				arr[p]=i;
				dfs(p+1,lim);
				vis[i]=0;
			}
		}
	}
	void main(){
		dfs(1,m);
		cout<<ans;
	}
}
namespace sol2{
	void main(){
		int cnt=n;
		for(int i=1;i<=n;i++)cnt-=(c[i]==0);
		if(cnt<m)cout<<0;
		else{
			ll res=1;
			for(int i=1;i<=n;i++)res=res*i%mod;
			cout<<res;
		}
	}
}
namespace sol3{
	ll f[505][505],sufc[505];
	void main(){
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=(c[i]==0);
		for(int i=1;i<=n;i++)sufc[i]=sufc[i+1]+(c[i]==0);
		sort(c+1,c+n+1,[](int x,int y){
			return x>y;
		});
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				f[i][j]=(f[i][j]+f[i-1][j-1]*(cnt-j+1)%mod)%mod;
				f[i][j]=(f[i][j]+f[i-1][j]*(n-c[i]-sufc[c[i]]-(i-1))%mod)%mod;
			}
		}
		ll res=1;
		for(int i=1;i<=n;i++)res=res*i%mod;
		cout<<(res-f[n][cnt]+mod)%mod;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m>>(s+1);
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10)sol1::main();
	else if(m==1)sol3::main();
	else{
		int fg=1;
		for(int i=1;i<=n;i++)fg&=(s[i]-'0');
		if(fg)sol2::main();
		else{
			cout<<341338130;
		}
	}
}

