#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[5010];
int ans;

void dfs(int pos,int Max,int sum,int cnt){
	if(pos==n+1){
		if(sum>Max*2&&cnt>=3){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	dfs(pos+1,max(Max,a[pos]),sum+a[pos],cnt+1);
	dfs(pos+1,Max,sum,cnt);
	return ;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
    	cout<<0;
    	return 0;
    }
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<ans;
	return 0;
}
