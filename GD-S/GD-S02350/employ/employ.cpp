#include <bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,d[N],a[N],vis[N],ans;
char s[N];
void dfs(int c){
	if(c==n+1){
		int w=0;
		for(int j=1;j<=n;j++){
			if(s[j]=='0'){
				continue;
			}else{
				if(j-1-w<d[a[j]])w++;
			}
		}
		if(w>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			a[c]=i;
			vis[i]=1;
			dfs(c+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	dfs(1);
	cout<<ans<<"\n";
}
