#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5001],ans=0;
void dfs(int x,int y,int maxx,int minn){//从x开始搜，搜y个小木棍 
    if(y==0&&maxx<minn){
		ans++;
		return;
	}
	else if(x==n)
	    return;
	int k=maxx;
	for(int i=x;i<=n;++i){
		maxx=a[i];
		if(maxx<minn){
			ans++;
			dfs(x,y-1,maxx,minn);
			y++;
			maxx=k;
		}
		dfs(x,y,k,minn+a[i]);
	}
	
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])
		    cout<<1;
		else
		    cout<<0;
		return 0;
	}
	for(int i=1;i<=n;++i)
	    for(int j=3;j<=n;++j)
		    dfs(i,j,0,0);
	cout<<ans<<endl;
	return 0;
}
