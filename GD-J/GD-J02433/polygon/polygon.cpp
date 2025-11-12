#include<bits/stdc++.h>
using namespace std;
int const MOD=998244353;
int a[5005],s[5005];
int n,cnt=0;
void dfs(int idx,int sum,int ma){
	if(idx==n+1){
		if(sum>ma*2){
			cnt++;
			cnt%=MOD;	
		}
		return;
	}
	if(sum+s[n]-s[idx-1]<ma*2)return;
	dfs(idx+1,sum+a[idx],max(ma,a[idx]));
	dfs(idx+1,sum,ma);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	if(m==1&&n>=30)cout<<(((n*(n-1))%MOD*(n-2))%MOD/2);
	else{
		dfs(1,0,0);
		cout<<cnt;
	}
	return 0;
}
