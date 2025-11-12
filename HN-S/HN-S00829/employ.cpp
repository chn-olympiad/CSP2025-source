#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 510
#define mod 998244353
int n,m,c[N];
char a[N];
int ans,b[N],vis[N];
void dfs(int now,int len){
	int i,j;
	vis[now]=1;
	b[len]=now;
	if(len==n){
		int cnt=0;
		for(i=1;i<=n;i++){
//			cout<<b[i]<<' ';
			if(a[i]=='0'){
				cnt++;
			}else{
				if(c[b[i]]<=cnt){
					cnt++;
				}
			}
		}
//		cout<<endl;
		int num=n-cnt;
		if(num>=m) ans++,ans%=mod;
		return ;
	}
	for(i=1;i<=n;i++){
		if(vis[i]) continue ;
		vis[i]=1;
		dfs(i,len+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j;
	cin>>n>>m>>(a+1);
	for(i=1;i<=n;i++){
		cin>>c[i];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) vis[j]=0,b[j]=0;
		dfs(i,1);
	}
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2


10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
