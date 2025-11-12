#include <bits/stdc++.h>
using namespace std;
const int N=5010;
const int MOD=998244353;
int n,a[N],ans;
bool vis[N];
void dfs(int x,int cnt,int sum,int maxx){
	if(x>n){
		if(sum>2*maxx) ans=(ans+1)%MOD;
		return;
	}
	dfs(x+1,cnt+1,sum+a[x],max(maxx,a[x]));
	dfs(x+1,cnt,sum,maxx);
}
int maxa; 
long long cheng1(int x){
	long long sum=1;
	int k1=1,k2=n;
	for(int i=1;i<=x;i++){
		sum=(sum*k2/k1)%MOD;
		k2--;
		k1++;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(maxa==1){
		long long sum=0;
		for(int i=3;i<=n;i++){
			sum=(sum+cheng1(i))%MOD;
		}
		cout<<sum;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
