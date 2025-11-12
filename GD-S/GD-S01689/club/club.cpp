#include<bits/stdc++.h>
#define ll long long
using namespace std;
char get_char;
bool sign;
bool isnum(const char &x){
	return ('0'<=x && x<='9');
}
void read(ll &x){
	x=0;
	get_char=getchar();
	sign=0; 
	while(!isnum(get_char)){
		if(get_char=='-')sign=1;
		get_char=getchar();
	}
	while(isnum(get_char)){
		x=(x<<3)+(x<<1)+(get_char-'0');
		get_char=getchar();
	}
	if(sign)x=-x;
}
ll n,lo[100005][5],len,hx,hy,ans,sum[100005],maxn;
bool flag1,flag2;
vector<ll>Q,P;
bool vis[100005];
void Input(){
	read(n);
	flag1=flag2=1;
	len=n>>1;
	maxn=0;
	for(int i=1;i<=n;i++){
		read(lo[i][1]);
		read(lo[i][2]);
		read(lo[i][3]);
		if(lo[i][3]!=0)flag1=flag2=0;
		else if(lo[i][2]!=0)flag1=0;
		sum[i]=max(lo[i][1],max(lo[i][2],lo[i][3]));
	}
	if(flag1){
		Q.clear();
		for(int i=1;i<=n;i++)Q.push_back(lo[i][1]);
		sort(Q.begin(),Q.end());
		while(len--){
			ans+=Q.back();
			Q.pop_back();
		}
	}else if(flag2){
		Q.clear();
		P.clear();
		for(int i=1;i<=n;i++)Q.push_back(lo[i][1]);
		for(int i=1;i<=n;i++)P.push_back(lo[i][2]);
		sort(Q.begin(),Q.end());
		sort(P.begin(),P.end());
		memset(vis,0,sizeof vis);
		hx=hy=len;
		while(n--){
			if(Q.back()<P.back() && hy){
				ans+=P.back();
				P.pop_back();
				hy--;
			}else if(hx){
				ans+=Q.back();
				Q.pop_back();
				hx--;
			}else{
				ans+=P.back();
				P.pop_back();
				hy--;
			}
		}
	}
	for(int i=n-1;i>=1;i--)sum[i]+=sum[i+1];
}
void dfs(ll u,ll a,ll b,ll c,ll love){
	if(love+sum[u]<=maxn)return;
	if(u==n+1){
		maxn=max(maxn,love);
		return;
	}
	if(a!=len)dfs(u+1,a+1,b,c,love+lo[u][1]);
	if(b!=len)dfs(u+1,a,b+1,c,love+lo[u][2]);
	if(c!=len)dfs(u+1,a,b,c+1,love+lo[u][3]);
}
void solve(){
	dfs(1,0,0,0,0);
	cout<<maxn<<'\n'; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	read(t);
	while(t--){
		ans=0;
		Input();
		if(ans!=0){
			cout<<ans<<'\n';
			continue;
		}
		solve();
	}
	return 0;
}
