#include<bits/stdc++.h>
using namespace std;
long long n,a[5002],aa[5003],k=3,ans=0;
void dfs(int step,int an){
	if(step>k){
		long long cnt=0,mx=0;
		for(int i=1;i<=k;i++){
			cnt+=aa[i];
			mx=max(mx,aa[i]);
		}
		if(cnt>mx*2)ans++;
		ans%=998244353;
		return ;
	}
	for(int i=an+1;i<=n;i++){
		aa[step]=a[i];
		dfs(step+1,i);
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		k=i;
		dfs(1,0);
		ans%=998244353;
	}
	cout<<ans%998244353;
	return 0;
} 
 
