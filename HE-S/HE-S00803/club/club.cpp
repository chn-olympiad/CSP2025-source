#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
int T,n,a[1000005][5],ans,s[5];
map<int,map<int,map<int,int> > >vis[1000005];
void dfs(int i,int x){
	if(i==n){
		ans=max(ans,x);
		return ;
	}
	if(vis[i][s[1]][s[2]][s[3]]>x){
		return ;
	}
	vis[i][s[1]][s[2]][s[3]]=x;
	for(int j=1;j<=3;j++){
		if(s[j]<n/2.0){
			s[j]++;
			dfs(i+1,x+a[i+1][j]);
			s[j]--;
		}
	}
}
signed main(){
//	ios::sync_with_stdio();
//	cin.tie(0);cout.tie(0);
	file("club");
	cin>>T;
	while(T--){
		s[1]=s[2]=s[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			vis[i].clear();
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		ans=0;
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}

