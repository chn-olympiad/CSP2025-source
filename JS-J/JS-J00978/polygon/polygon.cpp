#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5001],ans=0,pro[5001],goal;
void dfs(int x,int sum){
	if(sum>a[goal]){
		ans+=pro[goal-x]%998244353;
		ans%=998244353;
	}
	for(int i=x;i<n;i++){
		dfs(i,sum+a[i]);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	int f=0;
	for(int i=0;i<n;i++)if(a[i]!=1){
		f=1;
		break;
	}
	pro[0]=1;
	for(int i=1;i<5001;i++)pro[i]=pro[i-1]*2%998244353;
	if(f==0){
		int po=1;
		for(int i=0;i<n;i++){
			po=po*2%998244353;
		}
		cout<<(po-n-(n-1)*n/2-1+998244353*5)%998244353;
		exit(0);
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		goal=i;
		dfs(i,0);
	}
	cout<<ans;
}
