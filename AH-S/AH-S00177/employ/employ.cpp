#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[1000005];
const int P=998244353;
string s;
int ans=0;
int sol(){
	for(int i=1;i<=n;i++)
		if(s[i]=='0'||c[i]==0) return 0;
	ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%P;
	return ans;
}
namespace xx{
	int vis[1000005],p[100005];
	int ans=0,pre;
	void dfs(int pos){
		if(pos==n+1){
			if(n-pre>=m)
				ans++;
			return;
		}
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				p[pos]=i;vis[i]=1;
				if(pre>=c[i]||c[i]==0) dfs(pos+1);
				vis[i]=0;
			}
	}
	void main(){
		dfs(1);
		cout<<ans;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18){xx::main();return 0;}
	if(m==n){cout<<sol()<<endl;return 0;}
	return 0;
}
