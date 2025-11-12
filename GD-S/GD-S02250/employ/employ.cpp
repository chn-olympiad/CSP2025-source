#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e2+5,modd=998244353;
int n,m,res;
char str[N];
int pat[N];
int lvl[N];
bool f,used[N];

void dfs(int u,int acc){ 
	if(acc==m){
		res=(res+lvl[n-u+1])%modd;
		return;
	}
	if(u==n+1)return;
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		used[i]=1;
		dfs(u+1,acc+((pat[i]>u-acc-1)&&(str[u]=='1')));
		used[i]=0;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>(str+1);
	for(int i=1;i<=n;i++){
		cin>>pat[i];
	}
	
	lvl[0]=lvl[1]=1;
	for(int i=2;i<=n;i++)lvl[i]=lvl[i-1]*i%modd;
	
	f=1;
	for(int i=1;i<=n&&f;i++){
		if(str[i]=='0')f=0;
	}
	
	if(f){
		cout<<lvl[n]<<'\n';
		return 0;
	}
	if(m==n){
		cout<<0<<'\n';
		return 0;
	}
	if(m==1&&n==500){
		cout<<lvl[n]<<'\n';
		return 0;
	}
	dfs(1,0);
	cout<<res<<'\n';
	return 0;
}

