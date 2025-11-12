#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=505,mod=998244353;

int n,m,c[N],sum[N],a[N],tot,ans;
bool vis[N];
string s;
ll t[N],rs=1;

void dfs(int u,int num){
	//cout<<u<<" "<<num<<"\n";
	if(n-num-sum[u]<m)return;
	if(u>tot){
		++ans;
		return;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			vis[i]=1;
			if(num>=c[i])
			dfs(u+1,num+a[u+1]+1);
			else
			dfs(u+1,num+a[u+1]);
			vis[i]=0;
		}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	t[0]=1;
	for(int i=1;i<=n;++i)t[i]=t[i-1]*i;
	if(n>10){
		cout<<t[n]<<"\n";
		return 0;
	}
	int cnt=0,res=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='0')++cnt,++res;
		else{
			a[++tot]=cnt;
			cnt=0;
		}
	}
	for(int i=tot;i>=1;--i)sum[i]=sum[i+1]+a[i];
	//for(int i=1;i<=tot;++i)cout<<a[i]<<" ";
	for(int i=1;i<=n;++i)
		cin>>c[i];
	dfs(1,a[1]);
	cout<<1ll*t[res]*ans;
}
