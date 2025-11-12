#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
char s[N];
int a[N];
int vis[N],b[N];
int ans=0;
void dfs(int k){
	if(k==n+1){
		int np=0;
		int p=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				np++;
			}else if(s[i]=='0'){
				if(np>=b[i]){
					np++;
				}else{
					np=0;
					p++;
				}
			}
		}
		if(p>=m){
			ans++;
		}
		for(int i=1;i<=n;i++){
			b[i]=0;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		b[k]=a[i];
		dfs(k+1);
		vis[i]=0; 
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
