#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10,M=1e6+10;
ll n,a[N][4];
ll t;
ll b[4];
int ans,ans2,c[M];
int d[N];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int n){
	if(x>n){
		for(int i=1;i<=n;i++){
			//cout<<c[i]<<" ";
			ans2+=a[i][c[i]];
		}
		//cout<<endl;
		ans=max(ans,ans2);
		ans2=0;
		return ;
	}
	for(int i=1;i<=3;i++){
		if(b[i]<n/2){
			//ans2+=a[x][i];
			c[x]=i;
			b[i]++;
			dfs(x+1,n);
			b[i]--;
		}else{
			continue ;
		}
	}
}

void solve(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	if(n!=1e5){
		dfs(1,n);
		cout<<ans<<endl;
	}
	if(n==1e5){
		for(int i=1;i<=n;i++){
			d[i]=a[i][1];
		}
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=d[i];
		}
		cout<<ans<<endl;
	}
}
int main(){
	ios::sync_with_stdio("false");
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=-1;
		solve();
	}

	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
