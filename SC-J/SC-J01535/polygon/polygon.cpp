#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,ans,sum,mx,tot;
int a[N],vis[N],aw[N];
int dfs(int up,int dep){
	for(int i=up-1;i>=dep;i--){
		if(vis[i])continue;
		else{
			if(dep==1){
				sum+=a[i];
//				for(int k=1;k<=tot;k++){
//					cout<<aw[k]<<" ";
//				}
//				cout<<i<<endl;
				if(sum>mx)ans++;
				sum-=a[i];
				continue;
			}
			vis[i]=1;
			sum+=a[i];
			aw[tot++]=i;
			dfs(i,dep-1);
			tot--;
			sum-=a[i];
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			vis[j]=1;
			mx=a[j]*2;
			sum+=a[j];
			aw[++tot]=j;
			dfs(j,i-1);
			tot--;
			sum-=a[j];
			vis[j]=0;
		}
//		dfs(i);
	}
	cout<<ans;
	return 0;
	}

