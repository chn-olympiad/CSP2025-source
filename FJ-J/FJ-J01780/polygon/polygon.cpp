#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+100;
int n,a[N],ans=0,vis[N+1000]={0},sum[N]={0};
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]+sum[i-1];
	}
	sort(a+1,a+n+1);
	for(int k=3;k<=n;k++){
		for(int i=1;i<=n-k+1;i++){
			if(a[i+k-1]*2>sum[i+k-1]-sum[i-1]&&vis[sum[i+k-1]-sum[i-1]]==0){
				ans++;
				vis[sum[i+k-1]-sum[i-1]]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
