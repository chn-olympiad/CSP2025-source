#include<bits/stdc++.h>
#define mod 998244353
using namespace std;

int n, m;
long long sum, ans;
int f[510], c[510];
bool vis[510], vi[510];
int sb[1000];
int tot;

void dfs(int k,int w,int sum) {
	if(k>n) {
		if(sum>=m) {
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]) {
			continue;
		}
		if(w>=c[i]) {
			continue;
		}
		if(f[i]==0) {
			dfs(k+1,w+1,sum);
			continue;
		} 
		if(f[i]==1) {
			vis[i]=1;
			dfs(k+1,w,sum+1);
			vis[i]=0;
			continue;
		}
	}
	return ;
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d", &n,&m);
	string s;
	cin>>s;
	int s_len=s.length();
	for(int i=1;i<=s_len;i++) {	
		f[i]=s[i-1]-'0';
	} 
	for(int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
	} 
	dfs(1,0,0);
	cout<<(ans+1)/2;
	return 0;
} 
