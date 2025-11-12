#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
void dfs(int step,int sum,int cnt,int num){
	if(step==n+1){
		if(num>=3&&sum>2*cnt)ans++;
		return;
	}
	int l=max(cnt,a[step]);
	dfs(step+1,sum+a[step],l,num+1);
	dfs(step+1,sum,cnt,num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
