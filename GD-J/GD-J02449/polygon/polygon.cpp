#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[20005],xj,x,y,sum,ans,ma,dma,cnt;
int vis[10005];
void dfs(int x){
	if(sum>2*ma&&cnt>=3){
		ans++;
		return;
	}
	for(int i=x;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dma=ma;
			ma=max(ma,a[i]);
			sum+=a[i];
			cnt++;
			dfs(i);
			vis[i]=0;
			cnt--;
			ma=dma;
			sum-=a[i];
		}
	}
}
signed main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a) m++;
	}
	if(m<=1){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans+1;
	return 0;
} 
