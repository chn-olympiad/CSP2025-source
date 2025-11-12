#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
long long t,n,m,len[5],mxsiz,a[100005][5],anss,ans,pd_23,b[100005];
void dfs(int now,int anss){
	if(now>n){
		ans=max(ans,anss);
		return;
	}
	for(int i=1;i<=3;i++){
		if(len[i]>=mxsiz) continue;
		++len[i];
		dfs(now+1,anss+a[now][i]);
		--len[i];
	}
	return;
}
bool cmp(int a,int b){return a>b;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;pd_23=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(!a[i][2] and !a[i][3]) ++pd_23;// 12
		}
		mxsiz=n>>1,ans=-1e18;
		if(pd_23==n){
			ans=0;
			memset(b,0,sizeof(b));
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=mxsiz;i++) ans+=b[i];
			cout<<ans<<'\n';
			continue;
		}
		memset(len,0,sizeof(len));
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
