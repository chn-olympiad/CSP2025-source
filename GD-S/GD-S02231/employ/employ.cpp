#include<bits/stdc++.h>
using namespace std;
#define fio(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define tio() freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define cio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using ll=long long;
using pii=pair<int,int>;
const int N=510; 
const int mod=998244353;
int n,m;
char str[N];
int a[N];
int c[N];
int p[N];
bool vis[N];
ll ans;
void dfs(int x){
	if(x>n){
		int cnt=0,res=0;
		for(int i=1;i<=n;++i){
			if(cnt>=c[p[i]]){
				++cnt;
				continue;
			}
			if(a[i]){
				++cnt;
				continue;
			}
			++res;
		}
		if(res>=m)++ans;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vis[i]=1;
		p[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
bool fA=1;
int main(){
	fio("employ");
//	tio();
	cio();
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;++i){
		a[i]=str[i-1]-'0';
		a[i]^=1;
		if(a[i])fA=0;
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	if(m==n){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(c[i]==0)++cnt;
			if(a[i]==1)++cnt;
		}
		if(cnt)cout<<0;
		else{
			ll res=1;
			for(int i=1;i<=n;++i){
				(res*=i)%=mod;
			}
			cout<<res;
		}
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	
	if(fA){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(c[i]==0)++cnt;
		}
		if(n-cnt<m)cout<<0;
	}
	return 0;
} 
