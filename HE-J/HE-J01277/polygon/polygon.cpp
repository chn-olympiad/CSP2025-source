#include<bits/stdc++.h>
using namespace std;

int n;
const int N=5e3+5,mod=998244353;
long long a[N];
bool vis[N];
int s[N],cnt;
long long ans=0;
void dfs(int pos,int g,int len){
	if(g==len){
		long long mmax=0,sum=0;
		for(int i=1;i<=cnt;i++){
			mmax=max(mmax,a[s[i]]);
			sum+=a[s[i]];
		}
		if(sum>2*mmax){
			ans=(ans%mod+1)%mod;
		}
		return;
	} 
	if(pos>n) return;
	
	dfs(pos+1,g,len);
	vis[pos]=1;
	cnt++;
	s[cnt]=pos;
	dfs(pos+1,g+1,len);
	cnt--;
	vis[pos]=0;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=3;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(1,0,i);
	}
	cout<<ans%mod;
	
	return 0;
}
