#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ans,n,m,a[50],out[50],vis[50];
char ss[100000];
void dfs(int d){
	if(d==n+1){
		int tt=0,sum=0;
		for(int i=1;i<=d;i++){
			if(tt>=out[a[i]])tt++;
			else{
				if(ss[i]=='0')tt++;
				if(ss[i]=='1')sum++;
			}
		}
		if(sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		a[d]=i;
		vis[i]=1;
		dfs(d+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)ss[i+1]=s[i];
	for(int i=1;i<=n;i++)cin>>out[i];
	dfs(1);
	cout<<ans;
	return 0;
}
