#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
int n;
int a[5010];
int p;
int ans;
int t[5010];
ll sum,maxx;
int C(int x1,int x2){
	int ans=1;
	for(int i=(x1-x2+1);i<=x1;i++){
		ans=(ans*i)%mod;
	}
	for(int i=1;i<=x2;i++){
		ans=(ans/i)%mod;
	}
	return ans;
}
void dfs(int k,int mk,int p){
	if(k>mk) return ;
	if(k==mk){
		maxx=sum=0;
		for(int i=1;i<=k;i++){
			maxx=max(maxx,(ll)t[i]);
			sum+=t[i];
		}
		if(sum>(maxx*2))
		ans=(ans+1)%mod;
		
		return ;
	}
	for(int i=p+1;i<=n;i++){
		t[k+1]=a[i];
		dfs(k+1,mk,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p+=(a[i]==1);
	}
	if(p==n){
		for(int i=3;i<=n;i++){
			ans=(ans+C(n,i))%mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,0);
	}
	cout<<ans;
	return 0;
} 
/*
5
2 2 3 8 10
*/
