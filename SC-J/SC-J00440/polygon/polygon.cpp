#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5005;
const int mod=998244353;
int a[N],k[N],sum,n;
bool check(int n){
	int maxx=-1,sum=0,minx=1e18;
	for(int i=1;i<=n;i++) maxx=max(maxx,k[i]),sum+=k[i],minx=min(minx,k[i]);
	if(minx==0) return 0;
	if(sum>2*maxx) return 1;
	else return 0;
}
void dfs(int i,int x,int d){
	if(x==d+1||i==n+1){
		bool b=check(d);
		if(b==1) sum++;
		return ;
	}
	dfs(i+1,x,d);
	k[x]=a[i];
	dfs(i+1,x+1,d);
	k[x]=0;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int maxx=-1;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		if(sum>2*maxx) cout<<1;
		else cout<<0;
	}
    else if(maxx==1){
    	int sum=1;
    	for(int i=1;i<=n;i++) sum*=2,sum%=mod;
    	sum=sum-1-n-n*(n-1)/2;
    	sum=(sum+mod)%mod;
    	cout<<sum;
	}
	else{
		for(int i=3;i<=n;i++) dfs(1,1,i);
		cout<<sum;
	}
	return 0;
}