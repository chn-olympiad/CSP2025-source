#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5050], n, cnt=0;
int mxn=-1;
int C[5505][5505];
map<string, bool> mp;
bool vis[5050];
void dfs(int dep, int sum, int lon, int cho, string sta){
	if(cho>=3&&sum>lon*2&&!mp[sta]){
		mp[sta]=1;
		cnt=(cnt+1)%998244353;
		//cout << sta<<endl;
	}
	for(int i=dep+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i, sum+a[i], max(lon, a[i]), cho+1, sta+(char)(i+'0'));
			dfs(i, sum, lon, cho, sta);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		mxn=max(mxn, a[i]);
	}
	if(mxn<=1&&n>15){
		int ans=0;
		C[1][1]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=i;j++){
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%998244353;
			}
		}
		for(int i=3;i<=n;i++){
			ans=(C[n][i]+ans)%998244353;
		}
		cout <<ans;
		return 0; 
	}
	dfs(0,0,0,0,"");
	cout << cnt;
	return 0;
}
