#include<bits/stdc++.h>
using namespace std;
int a[5005];
int c[5005];
long long ans;
int n;
int cp(int a,int b){
	return a>b;
}
void dfs(int step,int cnt,int sum,int b){
	if(step==n+1){
		if(cnt>=3){
			if(c[cnt]*2<sum){
				ans++;
			}
		}
	}else{
		c[cnt+1]=a[step];
	dfs(step+1,cnt+1,sum+a[step],max(a[step],b));
		c[cnt+1]=0;
		dfs(step+1,cnt,sum,b);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans%998244353;
}
