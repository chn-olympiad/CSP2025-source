#include <bits/stdc++.h>
using namespace std;
int mod=998244353;
string s;
long long ans;
int n,m;
int c[505];
int f[505];
void dfs(int x){
	int cnt=0;
	if(x==n){
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&c[f[i]]>cnt){
			
				continue;
			}
			cnt++;
		}
		if(n-cnt>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	bool ff=0; 
	for(int i=1;i<=n;i++){
		ff=1;
		for(int j=1;j<=x;j++){
			if(f[j]==i){
			ff=0;
			break;
		}
		}
		if(ff==1){
			f[x+1]=i;
			dfs(x+1);
		}
	}
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
	dfs(0);
	cout<<ans%998244353;
    return 0;
}
