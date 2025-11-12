#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5050];
int sum[5050];
int ans=0;
void dfs(int t,int end,int now){
	if(t>end&&now>a[end+1]){ 
		ans++;ans%=998244353;
	}
	if(t>end)return ;
	if(sum[end]-sum[t-1]+now<a[end+1]){
		//cout<<"on my god";
		return ;
	}
	dfs(t+1,end,now+a[t]);
	dfs(t+1,end,now);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int reallyans=0;
	for(int i=3;i<=n;i++){
		ans=0;
		dfs(1,i-1,0);
		reallyans+=ans;
		reallyans%=998244353;
	}
	cout<<reallyans;
	return 0;
}
