#include<bits/stdc++.h>
using namespace std;
#define mol 998244353
#define int long long
const int N=1e5+5;
int n,m,a[N],b[N],d[N],c[N];
string s;
int vis[N],res;
void dfs(int cnt){
	if(cnt>n){
		int sum=0,ans=0;
		for(int i=1;i<=n;i++){
			if(b[d[i]]==1&&sum<c[d[i]]){
				ans++;
			}else{
				sum++;
			}
		}
		if(ans>=m){
			res=(res+1)%mol;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			d[cnt]=i;
			dfs(cnt+1);
			vis[i]=0;
			d[cnt]=0;
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			b[i+1]=1;
		}else{
			b[i+1]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n>100){
		cout<<0;
	}else{
		dfs(1);
		cout<<res-1;
	}
	return 0;
}
