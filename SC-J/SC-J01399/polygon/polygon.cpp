#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[25],ans;bool b[25];
void dfs(int now){
	if(now==n){
		ll mx=-1,sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]){
				sum+=a[i];
				cnt++;
				mx=max(a[i],mx);
			}
		}
		sum-=mx;
		if(sum>mx&&cnt>=3){
			ans++;
			ans%=998244353;
		}
		return;
	}
	b[now+1]=1;
	dfs(now+1);
	b[now+1]=0;
	dfs(now+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0);
	cout<<ans;
	return 0;
}
