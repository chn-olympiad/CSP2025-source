#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,a[5010],vis[5010],ans;
ll read(){
	ll cnt=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) cnt=cnt*10+ch-'0';
	return cnt*f;
}
bool check(){
	ll maxn=INT_MIN,sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			maxn=max(maxn,a[i]);
			sum+=a[i];
			cnt++;
		}
	}
	if(cnt>=3&&sum>2*maxn) return true;
	else return false;
}
void dfs(int x){
	if(x==n+2) return;
	if(x==n+1&&check()){
		ans++;
		ans%=mod;
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	time_t start=clock();
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	dfs(1);
	cout<<ans;
//	time_t duration=clock()-start;
//	cout<<'\n'<<duration<<"ms";
	return 0;
}
