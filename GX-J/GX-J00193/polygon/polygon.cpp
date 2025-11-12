#include<iostream>
#include<algorithm>
#define m(a,b,c) max(a,max(b,c)) 
using namespace std;
const int mod=998244353;
int n,ans;
int a[5005];
void dfs(int x,int bh,int tot,int mx){
	if(x==0){
		if(tot>2*mx)ans++;
		return;
	}
	for(int i=bh+1;i<=n;i++){
		dfs(x-1,i,tot+a[i],max(mx,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<(a[1]+a[2]+a[3]>2*m(a[1],a[2],a[3]));
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0);
	}
	cout<<ans%mod;
	return 0;
}
