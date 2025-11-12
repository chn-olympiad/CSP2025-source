#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
long long n,x[5005],a[5005],u,maxn;
long long ans;
void dfs(long long u,long long sum,long long ma,bool f){
	if(sum>2*ma&&f==1){
		ans++;
		ans%=p;
//		cout<<sum<<" "<<ma<<endl;
	}
	if(u>n) return;
	dfs(u+1,sum,ma,0);
	dfs(u+1,sum+a[u],max(ma,a[u]),1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		ans=1;
		for(int i=2;i<=n-2;i++){
			ans*=2;
			ans%=p;
		}
		cout<<(ans-1+p)%p;
		return 0;
	}
	dfs(2,a[1],a[1],1);
	dfs(2,0,0,0);
	cout<<ans;
	return 0;//ddddddddddddddddddddd
}