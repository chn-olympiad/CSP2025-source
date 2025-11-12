#include<bits/stdc++.h>
using namespace std;
const unsigned long long N=505,M=998244353;
bool s[N],f[N];
int c[N],n,m;
unsigned long long ans,A[N];
void dfs(const int x,int cnt){
	if(cnt>=m) return ans=(ans+A[n-x+1])%M,void();
	if(x==n+1||n-x+1<m-cnt) return;
	for(int i=1;i<=n;i++) if(!f[i])
		f[i]=1,dfs(x+1,cnt+(s[x]&&(x-1-cnt)<c[i])),f[i]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m,A[0]=1;
	for(int i=1;i<=n;i++) A[i]=A[i-1]*i%M;
	for(int i=1;i<=n;i++){
		char op;
		cin>>op,s[i]=op=='1';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0),cout<<ans;
}
