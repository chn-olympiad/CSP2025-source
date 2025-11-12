#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
int a[5005];
int len=3;
long long ans;
void dfs(int tp,int p,int sum){
	if(++tp==len){
		int pos=upper_bound(a+p,a+n,sum-1)-a;
		ans+=(pos-p);
		if(ans>=mod){
			ans-=mod;
		}
		return ;
	}
	for(int i=p;i<n;i++){
		dfs(tp,i+1,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(;len<=n;len++){
		dfs(0,0,0);
	}
	cout<<ans;
}
