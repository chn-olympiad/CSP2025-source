#include <bits/stdc++.h>
using namespace std;
const int MAX_N=5010,mod=998244353;
int n,a[MAX_N],mx=-1;
long long ans=0,cf[MAX_N];
void dfs(int x,int ma,int cnt,int la,int tmp){
	if(x>tmp){
		if(cnt>ma*2) ans=(ans+1)%mod;
		return ;
	}
	for(int i=la+1;i<=n;i++){
		dfs(x+1,a[i],cnt+a[i],i,tmp);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		cf[0]=1;
		cf[1]=1;
		for(int i=2;i<=n;i++){
			cf[i]=cf[i-1]*i;
		}
		for(int i=3;i<=n;i++){
			ans=(ans+cf[n]/cf[n-i]/cf[i])%mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(1,0,0,0,i);
	}
	cout<<ans;
	return 0;
}