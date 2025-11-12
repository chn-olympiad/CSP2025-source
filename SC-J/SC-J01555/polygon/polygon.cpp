#include<bits/stdc++.h>
using namespace std;

int n,a[5001],ans,f[6];
void dfs(int x,int sum,int mx,int t){
	if(x>=3&&sum>mx*2&&t==n+1){
		ans++;
		return;
	}
	if(t==n+1) return;
	f[t]=1;
	dfs(x+1,sum+a[t],max(mx,a[t]),t+1);
	f[t]=0;
	dfs(x,sum,mx,t+1);
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	dfs(0,0,0,1);
	cout<<ans<<endl;
    return 0;
}
