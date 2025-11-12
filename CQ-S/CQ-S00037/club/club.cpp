#include<bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=1e5+5;
int t,n,ans,a[N][5];
int b[N],c[N];
bool f1,f2,vis[N];
void dfs(int x,int cnt1,int cnt2,int cnt3,int sum){
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	if(cnt1+1<=n/2)
		dfs(x+1,cnt1+1,cnt2,cnt3,sum+a[x][1]);
	if(cnt2+1<=n/2)
		dfs(x+1,cnt1,cnt2+1,cnt3,sum+a[x][2]);
	if(cnt3+1<=n/2)
		dfs(x+1,cnt1,cnt2,cnt3+1,sum+a[x][3]);
}
void dfs2(int x,int cnt1,int cnt2,int sum){
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	if(cnt1+1<=n/2)
		dfs2(x+1,cnt1+1,cnt2,sum+a[x][1]);
	if(cnt2+1<=n/2)
		dfs2(x+1,cnt1,cnt2+1,sum+a[x][2]);
} 
void solve(){
	cin>>n;
	ans=0;
	rep(i,1,n){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0) f1=1;
		if(a[i][3]!=0) f2=1;
	}
	if(f1==0&&f2==0){
		rep(i,1,n){
			b[i]=a[i][1];
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=n/2;i++){
			ans+=b[n+1-i];
		}		
		cout<<ans<<"\n";
		return ;
	}
	if(f2==0){
		rep(i,1,n){
			b[i]=a[i][1];
			c[i]=a[i][2];
		}
		dfs2(1,0,0,0);
		cout<<ans<<"\n";
		return ;
	}
	dfs(1,0,0,0,0);
	cout<<ans<<"\n";
	return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
