#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int ans;
int a[N];
void dfs(int mx,int step,int sum,int x){
	if(a[step]>mx) mx=a[step];
	if(sum+a[step]<mx&&x>=3){
		ans++;
		ans%=998244353;
		return;
	}
	sum+=a[step];
	for(int i=step+1;i<=n;i++){
		dfs(mx,i,sum,x+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]) ans++;
	cout<<ans;
	
	return 0;
}

