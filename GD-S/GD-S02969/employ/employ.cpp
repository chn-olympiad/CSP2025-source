#include<bits/stdc++.h>
using namespace std;
const int N=600,mod=998244353;
string S;
int A[N],P[N],Fl[N];
int n,m,ans;
void dfs(int x,int cnt) {
	if(n-cnt<m) return;
	if(x==n+1) {ans+=(n-cnt>=m);ans%=mod;return;}
	if(x-cnt-1>=m) {ans+=P[n-x+1]; ans%=mod;return;}
//	cout<<x<<" "<<cnt<<endl;
	for(int i=1;i<=n;i++) {
		if(Fl[i]) continue;
		Fl[i]=1;
		int nc=cnt;
		if(S[x]=='0') nc++;
		else if(cnt>=A[i]) nc++;
		dfs(x+1,nc);
		Fl[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	P[0]=1; for(int i=1;i<=590;i++) P[i]=1ll*P[i-1]*i%mod;
	
	cin>>n>>m>>S; S=' '+S;
	
	for(int i=1;i<=n;i++) {
		cin>>A[i];
	}
	dfs(1,0);
	cout<<ans<<endl;
}

