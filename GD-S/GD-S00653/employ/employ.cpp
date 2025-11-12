#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const int INF=2147483647;
const int MAXN=1e2+5;
long long sum,n,m;
int c[MAXN];
bool vis[MAXN];
string s;
int reje(int m){
	long long ans=1;
	if(m==0) return 0;
	for(int i=1;i<=m;i++){
		i%=mod;
		(ans*=i)%=mod;
	}
	return ans;
}
void bfs(int k,int wtg) {
	if(k>n||(k-1)-wtg>=m){
		if(n-wtg>=m) sum=sum+1+reje(n-(k-1));
		sum%=mod;
		return;
	}
	for(int i=n;i>=1;i--){
		if(vis[i]) continue;
		vis[i]=1;
		bfs(k+1,wtg+(s[k]=='0'?1:0)+(c[i]<=wtg?1:0));
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	bool o=1;
	int q=0;
	for(int i=1;i<=s.size();i++) if(s[i]=='0') o=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0) q++;
	}
	if(o==1){
		cout<<reje(n-q);
		return 0;
	}
	sort(c+1,c+n+1);
	bfs(1,0);
	cout<<sum;
	return 0;
}
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
