#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,c[N],s[N],m,vis[N],a[N],ans;
int check(int a[]){
	int cnt=0,res=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0){
			++cnt;
			continue;
		}
		if(c[a[i]]<=cnt){
			++cnt;
			continue;
		}
		++res;
	}
	if(res>=m)return 1;
	return 0;
}
void dfs(int idx){
	if(idx==n+1){
		ans+=check(a);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		a[idx]=i;
		dfs(idx+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n<=20)
	{
		string ss;
		cin>>ss;
		for(int i=0;i<ss.length();i++){
			s[i+1]=ss[i]-'0';
		}
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		dfs(1);
		cout<<ans;
	}
	else cout<<0<<"\n";
	return 0;
}