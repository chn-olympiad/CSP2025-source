#include<bits/stdc++.h>
using namespace std;
int t,n,gnum[4],edge;
long long sum = 0;
int fa[10005],fb[10005],fc[10005];
inline void dfs(int a,int b,int c,int p,long long ans){
	if(a + b + c == n&&p == n+1){
		if(ans>sum)sum = ans;
		return;
	}
	if(a<edge)
	dfs(a+1,b,c,p+1,ans+fa[p]);
	if(b < edge)
	dfs(a,b+1,c,p+1,ans + fb[p]);
	if(c < edge)
	dfs(a,b,c+1,p+1,ans + fc[p]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		sum = -1;
		memset(fa,0,sizeof(fa));
		memset(fb,0,sizeof(fb));
		memset(fc,0,sizeof(fc));
		edge = n>>1;
		for(int j = 1;j <= n;j++){
			cin >> fa[j] >> fb[j] >> fc[j];
		}
		bool flag = 1;
		for(int j = 1;j <= n;j++){
			if(fb[i]||fc[i])
			flag = 0;
		}
		if(flag){
			sort(fa+1,fa+1+n);
			sum = 0;
			for(int j = 1;j <= edge;j++){
				
				sum += fa[n-j+1];
			}
		}else{
			dfs(0,0,0,1,0);
		}
		
		cout << sum << endl;
	}
	
	return 0;
}
