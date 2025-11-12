#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m,a[N],ans;
string s;
bool vis[N];
void dfs(int x,int sum,int tp,int id){
	vis[x]=1;
	int xtp=tp,xsm=sum;
	if(x){
		if(tp<a[x]){
			if(s[id]=='1') ++xsm;
			else ++xtp;
		}
	}
	if(xsm>=m) ++ans,ans%=MOD;
	for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,xsm,xtp,id+1);
	vis[x]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	a[0]=1e9;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	dfs(0,0,0,-1);
	printf("%d",ans);
	return 0;
}
