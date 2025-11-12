#include<bits/stdc++.h>
using namespace std;
int n,m,c[555],ans,a[555],fl[555];
string s;
void dfs(int id){
	if(id==n+1){
		int fail_cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||fail_cnt>=c[a[i]])fail_cnt++;
		}
		if(n-fail_cnt>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(fl[i])continue;
		a[id]=i;
		fl[i]=1;
		dfs(id+1);
		fl[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
