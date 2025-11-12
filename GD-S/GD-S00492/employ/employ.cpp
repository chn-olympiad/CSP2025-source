#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=25;
int n,m,ans,a[N],bz[N];
char s[N];
bool vis[N]; 
void dfs(int x){
	if(x==n+1){
		int res=0;
		for(int i=1;i<=n;i++){
			if(res>=a[bz[i]]){
				res++;
			}
			else if(s[i]=='0')	res++;
			else	;
		}
		if(n-res>=m)	ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			bz[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>s[i];
	for(int i=1;i<=n;i++)	cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
