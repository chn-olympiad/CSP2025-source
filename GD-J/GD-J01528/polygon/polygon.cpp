#include<iostream>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N=5010,MOD=998244353;
int n,a[N];
bool vis[N],specA=1;
typedef long long ll;
ll dfs(int edge,int maxe,ll sum,int last){
	if(edge>n-last)return 0;
	if(edge==0){
		if(sum>maxe*2){
//			for(int i=1;i<=ans[0];i++){
//				cout<<ans[i]<<" ";
//			}cout<<endl;
			return 1;
		}
		else return 0;
	}
	ll cur=0;
	for(int i=last+1;i<=n;i++){
		cur+=dfs(edge-1,max(maxe,a[i]),sum+a[i],i)%MOD;
	}
	return cur%MOD;
}
ll solve(int x){
	ll sum=1;
	for(int i=2;i<=x;i++){
		sum=sum*i%MOD;
		sum%=MOD;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//    cout<<solve(6); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1)specA=0;
	}
	if(specA){
		ll cnt=0,sn=solve(n)%MOD;
		for(int i=3;i<=n;i++){
			cnt+=(sn/(solve(i)*solve(n-i))%MOD);
			cnt%=MOD;
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=3;i<=n;i++){
		ans+=dfs(i,0,0,0);
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}
