#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ansr=0,maxt=-1;
void dfs(int now,int ans,int maxn,int sum){
	//
	
	if(now>n){
		if(ans>maxn*2 && sum>=3){
			ansr++;
		}
		return ;
	}
	//
	dfs(now+1,ans+a[now],max(maxn,a[now]),sum+1);
	dfs(now+1,ans,maxn,sum);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxt=max(maxt,a[i]);
	}
	if(maxt==1){
		long long x=0;
		for(int i=3;i<=n;i++){
			long long cosine=0;
			for(int j=n-i+1;j<=n;j++){
				cosine*=j;
			}
			for(int j=1;j<=i;j++){
				cosine/=j;
			}
			x=(x+cosine)%988244353;
		}
		cout<<x;
	}
	else {
		dfs(1,0,0,0);
		cout<<ansr%988244353;
	}
	return 0;
}
