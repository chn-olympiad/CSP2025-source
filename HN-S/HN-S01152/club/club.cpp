#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=2e6+10;
struct node{
	int a,b,c;
}x[N];
bool vis[N];
int maxn=-1,n;
void dfs(int u,int as,int bs,int cs,int sum){
//	cout<<u<<endl;
	if(u==n+1){
		maxn=max(maxn,sum);
		return ;
	}
	for(int i=u;i<=n;i++){
		int s=n/2;
		if(vis[i]==0&&as+1<=s){
			vis[i]=1;
			dfs(u+1,as+1,bs,cs,sum+x[i].a);
			vis[i]=0;
		}
		if(vis[i]==0&&bs+1<=s){
			vis[i]=1;
			dfs(u+1,as,bs+1,cs,sum+x[i].b);
			vis[i]=0;
		}
		if(vis[i]==0&&cs+1<=s){
			vis[i]=1;
			dfs(u+1,as,bs,cs+1,sum+x[i].c);
			vis[i]=0;
		}
	}
	return ;
}
bool cmpa(node x,node y){
	return x.a>y.a;
}
bool cmpb(node x,node y){
	return x.b>y.b;
}
void solve(){
	cin>>n;
	bool f=1,f2=1;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b>>x[i].c;
		if(x[i].b!=0||x[i].c!=0) f=0;
		if(x[i].c!=0) f2=0;
	}
	if(f||f2){
		int sum1=0,sum2=0;
		sort(x+1,x+1+n,cmpa);
		for(int i=1;i<=n/2;i++) sum1+=x[i].a;
		if(f){
			cout<<sum1<<' ';
			return ;
		}
		for(int i=n/2+1;i<=n;i++) sum1+=x[i].b;
		sort(x+1,x+1+n,cmpb);
		for(int i=1;i<=n/2;i++) sum2+=x[i].b;
		for(int i=n/2+1;i<=n;i++) sum2+=x[i].a;
		if(f2){
			cout<<max(sum1,sum2)<<' ';
			return ;
		}
	}
	memset(vis,0,sizeof vis);
	maxn=-1;
	dfs(0,0,0,0,0);
	cout<<maxn<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
