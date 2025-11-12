#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+10;
ll t,n,a[N][4],f[4],sum,ans;
struct node{
	ll x,y;
}b[N];
bool cmp(node x,node y){
	return x.x>y.x;
}
void dfs(ll x){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	if(f[1]>0){
		f[1]--;
		sum+=a[x][1];
		dfs(x+1);
		sum-=a[x][1];
		f[1]++;
	}
	if(f[2]>0){
		f[2]--;
		sum+=a[x][2];
		dfs(x+1);
		sum-=a[x][2];
		f[2]++;
	}
	if(f[3]>0){
		f[3]--;
		sum+=a[x][3];
		dfs(x+1);
		sum-=a[x][3];
		f[3]++;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		bool flag=0;
		for(int i=1;i<=3;i++)f[i]=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0)flag=1;
		}
		if(flag==0){
			ll b[N]={};
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1,greater<ll>());
			ll ans=0;
			for(int i=1;i<=n/2;i++)ans+=b[i];
			cout<<ans<<'\n';
			continue;
		}
		dfs(1);
		cout<<ans<<'\n';
		ans=0;
		memset(f,0,sizeof f);
	}
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
