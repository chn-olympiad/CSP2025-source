#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
int c[505];
int a[505],cnt;
int vs[505];
int ans;
void dfs(int j){
	if(j==n){
		int l=0,mm=0;
		for(int i=1;i<=n;i++){
			if(mm>=c[a[i]]){
				mm++;
			}else if(s[i-1]=='0'){
				mm++;
			}else{
				l++;
			}
		}
		if(l>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vs[i]==0){
			vs[i]=1;
			a[j+1]=i;
			dfs(j+1);
			vs[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}

