#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,a[N],ans;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int id,int maxn,int cnt,int m){
	maxn=max(maxn,a[id]);
	cnt+=a[id];
	m++;
	if(m>=3&&cnt>2*maxn) ans=(ans+1)%998244353;
	for(int i=id+1;i<=n;i++){
		dfs(i,maxn,cnt,m);
	}
}
int C(int n,int k){
	long long ans=1;
	if(k>n-k) k=n-k;
	for(int i=n;i>=k;i--){
		ans=(ans*i)%998244353;
	}
	for(int i=1;i<=k;i++) ans/=i;
	return int(ans);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>20){
		for(int i=3;i<=n/2;i++) ans=ans+C(n,i)%998244353+C(n,i)%998244353;
		cout<<ans;
	}else{
		for(int i=1;i<=n-2;i++){
			dfs(i,a[i],0,0);
		}
		cout<<ans;
	}
	
	return 0;
}
