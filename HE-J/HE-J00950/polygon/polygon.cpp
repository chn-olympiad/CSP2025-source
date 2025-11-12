#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll N=1e4+100;
const ll M=998244353;
int n;
ll ans=0;
int a[N];
int step[N];
void dfs(int k,int maxn,ll sum,int si){
	if(sum>maxn*2){
		ans=(ans+1)%M;
	}
	if(k==n+1 || si==n){
		return;
	}
	for(int i=si+1;i<=n;i++){
		step[k]=a[i];
		dfs(k+1,max(maxn,a[i]),sum+a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			step[1]=a[i];
			step[2]=a[j];
			dfs(3,max(a[i],a[j]),a[i]+a[j],j);
		}
	}
	cout<<ans;
	return 0;
}
