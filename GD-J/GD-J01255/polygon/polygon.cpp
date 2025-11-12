#include<bits/stdc++.h>
using namespace std;
int a[5001];
long long mem[5001];
int n;
const long long mod=998244353;
long long ans=0;
void dfs(int tot,int cur,int pick){	
	int total=tot;
	if(cur>n) return;	
	if(total>a[cur]&&pick>=2){
		ans++;
		ans%=mod;
	}
	total+=a[cur];
	dfs(total,cur+1,pick+1);
	total-=a[cur];
	dfs(total,cur+1,pick);
	return;
}
int main(){
	freopen("polygon4.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>=50){
		long long ys=0;
		long long k1=n*(n-1)/2,k2=n,k3=1,kk=1;
		for(int i=1;i<=n;i++){
			kk=(kk*2)%mod;
		}
		ys=(kk-k1-k2-k3+mod)%mod;
		cout<<ys<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,1,0);
	cout<<ans<<endl;
	return 0;
}
