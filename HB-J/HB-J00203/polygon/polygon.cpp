#include<bits/stdc++.h>
using namespace std;
int n,a[5003],ans;
void dfs(int x,int cn,int now){
	if(x>=3&&cn>a[now-1]*2){
		ans++;
		ans%=998244353;
	}
	if(x==n)return;
	for(int i=now;i<=n;i++)dfs(x+1,cn+a[i],i+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    dfs(0,0,1);
    cout<<ans;
    return 0;
}
