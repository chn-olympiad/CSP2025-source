#include<bits/stdc++.h>
#define ll long long
const ll maxn=6000;
const ll MOD=998224353;
using namespace std;
ll n,arr[maxn],ans,cntma,cnt1,vis[maxn],yivis,zonghe,zanshi;
void dfs(ll qidian,ll mubiao){
	if(yivis==mubiao){
		if(zonghe>2*cntma)ans=(ans+1)%MOD;
		return;
	}
	for(ll i=1;i+qidian<=n;i++){
		if(!vis[i+qidian]){
			vis[i+qidian]=1;
			zanshi=cntma;
			cntma=max(cntma,arr[i+qidian]);
			zonghe+=arr[i+qidian];
			dfs(i+qidian,mubiao);
			zonghe-=arr[i+qidian];
			cntma=zanshi;
			vis[i+qidian]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]==1)cnt1++;
	}
	if(n==3){
		for(ll i=1;i<=n;i++){
			cntma=max(cntma,arr[i]);
		}
		for(ll j=1;j<=n;j++){
			ans+=arr[j];
		}
		if(ans>cntma*2)ans=1;
		else ans=0;
	}else if(cnt1==n){
		ans=1;
		for(ll i=n;i>=n-2;i--){
			ans=(ans*i)%MOD;
		}
		ans=(ans/3)%MOD;
		ans=(ans/2)%MOD;
	}
	else{
		for(ll len=3;len<=n;len++){
			for(ll qi=1;qi+len<=n;qi++){
				dfs(qi,len);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
