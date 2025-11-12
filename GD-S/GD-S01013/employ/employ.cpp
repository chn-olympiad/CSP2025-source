#include<bits/stdc++.h>
using namespace std;
const int N=520;
#define int long long
const int mod=998244353;
string s;
vector<int> blk;
int n,c[N],m,ans;
int a[N],len,d[N];
void dfs(int depth){
	if(depth==n+1){
		if(len<m)
			return;
		for(int i=1;i<=len;i++)
			d[i]=a[i];
		sort(d+1,d+1+len);
		for(int i=0,j=1;i<blk.size()&&j<=len;i++,j++){
			if(blk[i]>=d[j])
				return;
		}
		ans++;
		return;
	}
	a[++len]=c[depth];
	dfs(depth+1);
	len--;
	dfs(depth+1);
}
bool vis[20];
void dfs1(int depth){
	if(depth==n+1){
		int res=0;
		for(int cnt=0,i=1;i<=n;i++){
			if(s[i]=='0'){
				cnt++;
				continue;
			}
			else{
				if(cnt>=c[a[i]]){
					cnt++;
					continue;
				}
				else{
					cnt=0;
					res++;
				}
			}
		}
		ans+=(res>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])
			continue;
		a[depth]=i;
		vis[i]=1;
		dfs1(depth+1);
		a[depth]=0;
		vis[i]=0;
	}
}
int taskA,talen;
int pre[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	pre[0]=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		talen+=(c[i]>=1);
		pre[i]=pre[i-1]*i%mod;
	}
	dfs1(1);
	cout<<ans;
	return 0;
}
