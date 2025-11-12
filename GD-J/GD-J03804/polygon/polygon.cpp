#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n;
long long dp[N][N],a[N],b[N],ans,sum,mx,t;
bool v[N]; 

void dfs(int idx,int I,int cnt){
	if(cnt==I){
		if(sum>mx*2)ans++;
		return ;
	}
	for(int i=idx;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			sum+=a[i];
			t=mx;
			mx=max(mx,a[i]);
			dfs(i,I,cnt+1);
			v[i]=0;
			sum-=a[i];
			mx=t;
		}
	}
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(1,i,0);
	}
	cout<<ans%998244353;
	return 0;
}
