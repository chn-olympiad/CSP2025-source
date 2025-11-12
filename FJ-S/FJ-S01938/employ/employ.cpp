#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int mod=998244353;


int rd() {
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') {
		x=x*10+ch-'0';
		ch=getchar();
	} 
	return x*f; 
}
const int N=1e5;
int n,m,c[N];
char s[N];
int order[N],f[N],add[N],ans=0;
int b1=0,b2=0;
void dfs(int t) {
	if(b2+add[t]<m) return;
	if(t>n) {
	///	cout<<b1<<' '<<b2<<'\n';
		if(b2>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(f[i]==1) continue;
		f[i]=1;
		int l1=b1,l2=b2;
		if(c[i]<=b1) b1++;
		else {
			if(s[t]=='0') b1++;
			else b2++;
		}
		dfs(t+1);
		b1=l1,b2=l2;
		f[i]=0;
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd(); m=rd();
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=n;i>=1;i--) {
		add[i]=add[i+1]+s[i]-'0';
	}

	for(int i=1;i<=n;i++) c[i]=rd(); 	
	if(add[1]==n) {
		bool chf=1;
		for(int i=1;i<=n;i++)  chf=0;
		if(chf==1) {
			ans=1;
			for(int i=n;i>=1;i--) {
				ans=(ans*i)%mod ;
			}
			cout<<ans<<'\n';
			return 0;
		}
		
	} 
	dfs(1);
	cout<<ans;
	return 0;
} 
