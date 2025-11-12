#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
//Ren5Jie4Di4Ling5%
int a[N][4];
int path[N];
int n;
long long ans;
int vis[N];
void dfs(int x){
	if(x==n){
		long long sum=0;
		for(int i=0;i<n;i++){
//			cout<<path[i]<<" ";
			sum+=path[i];
		}
//		cout<<endl;
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]+1<=n/2){
			path[x]=a[x+1][i];
			vis[i]++;
			dfs(x+1);
			vis[i]--;
		}
	}
}
bool tpA(){
	for(int i=1;i<=n;i++){
		if(a[i][2]!=0||a[i][3]!=0)	return 0;
	}
	return 1;
}
struct node{
	int a1,a2,a3;
}num[N];
bool cmp(node x,node y){
	return x.a1>y.a1;
}
void solve(){
	cin>>n;
	memset(a,0,sizeof(a));
	memset(path,0,sizeof(path));
	for(int i=1;i<=n;i++)	cin>>a[i][1]>>a[i][2]>>a[i][3];
	if(tpA()){
		for(int i=1;i<=n;i++){
			num[i].a1=a[i][1];
			num[i].a2=a[i][2];
			num[i].a3=a[i][3];
		}
		sort(num+1,num+n+1,cmp);
		long long sum=0;
		for(int i=1;i<=n/2;i++){
			sum+=num[i].a1;
		}
		cout<<sum<<endl;
		return ;
	}
	ans=0;
	memset(vis,0,sizeof(vis));
	dfs(0);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)	solve();
	return 0;
}
