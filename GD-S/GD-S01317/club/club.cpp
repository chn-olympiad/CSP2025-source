#include <bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int n;
int d=n/2;
int dp[N][4];
struct node{
	int f,s,t;
}b[N];
int a[N][4];
bool cmp(node a,node b){
	return (a.f+a.s+a.t)<(b.f+b.s+b.t);
}
int sum[N];
void solve_1(){
	int sum=0;
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n/2;i++){
		sum+=b[i].f;
	}
	cout<<sum;
}
int cnt[4];
bool vis[N][4];
int mx=-1e9;
void dfs(int dep,int cnt1){
	if(dep==n+1){
		mx=max(mx,cnt1); 
	}
	for(int i=1;i<=3;i++){
		if(!vis[dep][i]&&cnt[i]<(n/2)){
			vis[dep][i]=1;
			cnt[i]++;
			dfs(dep+1,cnt1+a[dep][i]);
			vis[dep][i]=0;
			cnt[i]--;
		}
	}
}
void dfs_2(int dep,int cnt1){
	if(dep==n+1){
		mx=max(mx,cnt1); 
	}
	for(int i=1;i<=2;i++){
		if(!vis[dep][i]&&cnt[i]<(n/2)){
			vis[dep][i]=1;
			cnt[i]++;
			dfs_2(dep+1,cnt1+a[dep][i]);
			vis[dep][i]=0;
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		mx=0;
		memset(vis,0,sizeof vis);
		memset(cnt,0,sizeof cnt);
		int cnt1=0,cnt2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]={a[i][1],a[i][2],a[i][3]};
			if(a[i][2]==0){
				cnt1++;
			}if(a[i][3]==0){
				cnt2++;
			}
		}
		//nÎªÅ¼Êý
		if(cnt1==n&&cnt2==n){
			solve_1();
			continue;
		}else if(cnt2==n&&a[1][1]!=0){
			dfs_2(1,0);
			cout<<mx<<'\n';
		}else{
			dfs(1,0);
			cout<<mx<<'\n';
		}
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
