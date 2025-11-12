#include<iostream>

using namespace std;

using ll=long long;
ll mod=998244353;
const int N=5e2+5;
int c[N];
int cnt1,cnt0;
int cc[N];
ll tot;
ll ans[N],top;
int n,m;
bool vis[N];

bool check(){
	ll pre=0,cnt=0;
	for(int i=1;i<=top;i++){
		if(c[i]>pre)
			cnt++;
		if(cc[i])
			pre++;
	}
	return cnt>=m;
}
void dfs(int now){
	for(int i=now;i<=n;i++){
		if(vis[i])
			continue;
		vis[i]=1;
		ans[++top]=c[i];
		if(check())
			tot++;
		dfs(now+1);
		vis[i]=false;
		--top;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='0')
			cc[i]=0;
		else if(ch=='1')
			cc[i]=1;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	
	dfs(1);
	
	cout<<tot<<'\n';
	return 0;
}