#include<bits/stdc++.h>
#define up(i,l,r) for(int i=l,END##i=r;i<=END##i;i++)
#define dn(i,l,r) for(int i=l,END##i=r;i>=END##i;i--)
#define ve vector<int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define great greater<int>
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
using namespace std;
const int INF=0x3f3f3f3f,N=507,p=998244353;
string s;
int n,m,a[N];
i64 ans;
bool f[N];
int id[N];
void dfs(int x){
	if(x==n+1){
		int now=0,k=0;
		up(i,1,n){
			if(s[i]=='1'&&now<a[id[i]]) k++;
			else now++;
		}
		if(k>=m) ans++;ans%=p;
		return;
	}
	up(i,1,n) if(!f[i]){
		f[i]=1,id[x]=i;dfs(x+1);f[i]=0;
	}
}
namespace sol{
	i64 read(){
		i64 x=0,f=0;
		char c=getchar();
		while(c<'0'||c>'9') f|=c=='-',c=getchar();
		while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
		return f?-x:x;
	}
	void write(i64 x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	void Dianaqwq(){
		n=read(),m=read();
		cin>>s;
		up(i,1,n) a[i]=read();
		s=' '+s;
		bool f=0,o=1;
		up(i,1,n) f|=(s[i]-'0'),o&=(s[i]-'0');
		if(!f) return puts("0"),void();
		if(n==m){
			if(!o) return puts("0"),void();
			i64 ans=1;
			up(i,1,n) (ans*=i)%=p;
			write(ans);return;
		}
		dfs(1);
		write(ans);
	}
}
using namespace sol;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	Dianaqwq();
	return 0;
}
