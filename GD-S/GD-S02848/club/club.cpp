#include<iostream>
#include<algorithm>
#include<map> 
#define int long long
using namespace std;
int n,t,a[1000001][4],maxn[1000001],ans,cnt;
map<int,map<int,map<int,map<int,map<int,int> > > > >mp;
void dfs(int k,int l1,int l2,int l3,int s){
	if(s+maxn[k]<ans) return;
    if(l1>n/2||l2>n/2||l3>n/2) return;
	if(k==n+1){
		ans=max(ans,s);
		return;
	}
	cnt++;
	if(a[k][1]>a[k][2]&&a[k][2]>a[k][3]){
		dfs(k+1,l1+1,l2,l3,s+a[k][1]);
	    dfs(k+1,l1,l2+1,l3,s+a[k][2]);
	    dfs(k+1,l1,l2,l3+1,s+a[k][3]);
	}
	if(a[k][1]>a[k][3]&&a[k][3]>a[k][2]){
		dfs(k+1,l1+1,l2,l3,s+a[k][1]);
	    dfs(k+1,l1,l2,l3+1,s+a[k][3]);
	    dfs(k+1,l1,l2+1,l3,s+a[k][2]);
	} 
	if(a[k][2]>a[k][1]&&a[k][1]>a[k][3]){
		dfs(k+1,l1,l2+1,l3,s+a[k][2]);
	    dfs(k+1,l1+1,l2,l3,s+a[k][1]);
	    dfs(k+1,l1,l2,l3+1,s+a[k][3]);
	} 
	if(a[k][2]>a[k][3]&&a[k][3]>a[k][1]){
		dfs(k+1,l1,l2+1,l3,s+a[k][2]);
	    dfs(k+1,l1,l2,l3+1,s+a[k][3]);
	    dfs(k+1,l1+1,l2,l3,s+a[k][1]);
	} 
	if(a[k][3]>a[k][2]&&a[k][2]>a[k][1]){
		dfs(k+1,l1,l2,l3+1,s+a[k][3]);
	    dfs(k+1,l1,l2+1,l3,s+a[k][2]);
	    dfs(k+1,l1+1,l2,l3,s+a[k][1]);
	} 
	if(a[k][3]>a[k][1]&&a[k][1]>a[k][2]){
		dfs(k+1,l1,l2,l3+1,s+a[k][3]);
	    dfs(k+1,l1+1,l2,l3,s+a[k][1]);
	    dfs(k+1,l1,l2+1,l3,s+a[k][2]);
	} 
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
 freopen("club.in","r",stdin);
	 freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cnt=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
			cin>>a[i][j];
		for(int i=n;i>=1;i--){
			int man=-1e9;
			for(int j=1;j<=3;j++)
			man=max(man,a[i][j]);
			maxn[i]=maxn[i+1]+man;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
}
