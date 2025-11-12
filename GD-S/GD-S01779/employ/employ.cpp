#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define db double
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int MAXX=505;
const int P=998244353;

int n,m,ans;
string s;
int a[MAXX],c[MAXX];
int vis[MAXX],b[MAXX];
void sol() {
	int ly=0;
	for(int i=1;i<=n;i++) {
		if((i-1-ly)>=c[b[i]]) continue;
		if(a[i]) ly++;
	}
	if(ly>=m) ans++,ans%=P;
}
void dfs(int pos) {
	if(pos==n+1) {
		sol();
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]) continue;
		b[pos]=i,vis[i]=1,dfs(pos+1),vis[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) a[i]=(int)(s[i-1]-'0');
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;

	return 0;
}

