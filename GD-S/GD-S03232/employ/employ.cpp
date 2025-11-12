#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 510;
string s;
int c[N];
int p[N];
bool vis[N];
int ans;
void dfs(int cnt){
	if(cnt==n){
		int x = 0;
		int f = 0;
		for(int i = 1;i<=n;i++){
			if(s[i-1]=='1'&&c[i]-x>0){
				f++;
			}
			else if(s[i-1]=='0'){
				x++;
			}
		}
		if(f>=m) ans++;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			p[cnt+1] = i;
			dfs(cnt+1);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
