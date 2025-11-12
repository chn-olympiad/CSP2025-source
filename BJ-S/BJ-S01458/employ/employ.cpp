#include<bits/stdc++.h>
#define N 600
#define mod 998244353
using namespace std;
int n,m,c[N],now[N],ans=0,cnt1,cnt2;
string s;
bool used[N];
void dfs(int step){
	if(step==n){
		cnt1=cnt2=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt1>=c[now[i]])cnt1++;
			else cnt2++;
		}
		if(cnt2>=m)ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			now[step+1]=i;
			used[i]=1;
			dfs(step+1);
			used[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	s="A"+s;
	dfs(0);
	cout<<ans;
	return 0;
}
