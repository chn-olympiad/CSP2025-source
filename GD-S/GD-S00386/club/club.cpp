#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define INFF 0x3f
#define INF 0x3f3f3f3f
const int N=1e5+10;
int n,t;
int a[N][5];
int ans;
bool vis[N];
void dfs(int dep,int s1,int s2,int s3,int x){
	if(dep==n+1){
		ans=max(x,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		if(s1){
			vis[i]=1;
			dfs(dep+1,s1-1,s2,s3,x+a[i][1]);
			vis[i]=0;
		}
		if(s2){
			vis[i]=1;
			dfs(dep+1,s1,s2-1,s3,x+a[i][2]);
			vis[i]=0;
		}
		if(s1){
			vis[i]=1;
			dfs(dep+1,s1,s2,s3-1,x+a[i][3]);
			vis[i]=0;
		}	
	}
	
}
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i][2]!=0||a[i][3]!=0) return 0;
	}
	return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(check()){
			priority_queue<int,vector<int>,less<int> > q;
			for(int i=1;i<=n;i++) q.push(a[i][1]);
			for(int i=1;i<=n/2;i++){
				ans+=q.top();
				q.pop();
			}
			cout<<ans<<endl;
			continue;
		} 
		dfs(1,n/2,n/2,n/2,0);
		cout<<ans<<endl;
	}
	return 0;
}

