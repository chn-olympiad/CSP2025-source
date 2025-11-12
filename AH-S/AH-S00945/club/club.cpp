#include"bits/stdc++.h"
using namespace std;
struct node{
	int a;
	int op;
	int id;
	bool operator <(const node &x) const {
		return a>x.a;
	}
};
node aa[300005];
bool vis[100005];
int a[100005][5];
int dp1[100005];
int dp2[100005];
int n;
int ans=0;
int dfs(int x,int c1,int c2,int c3,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return sum;
	}
	int mx=0;
	if(c1<(n>>1))
		mx=max(mx,dfs(x+1,c1+1,c2,c3,sum+a[x][1]));
	if(c2<(n>>1))
		mx=max(dfs(x+1,c1,c2+1,c3,sum+a[x][2]),mx);
	if(c3<(n>>1))
		mx=max(dfs(x+1,c1,c2,c3+1,sum+a[x][3]),mx);
	return mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		memset(vis,false,sizeof vis);
		memset(dp1,0,sizeof dp1);
		memset(dp2,0,sizeof dp2);
		cin>>n;
		int cnt=0;
		bool f=true,ff=true;
		long long sum=0,sum1=0,sum2=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			sum+=x+y+z;
			sum1+=x;
			sum2+=y;
			if(z)
				ff=false;
			if(y||z)
				f=false;
			a[i][1]=x;
			a[i][2]=y;
			a[i][3]=z;
			aa[++cnt]={x,1,i};
			aa[++cnt]={y,2,i};
			aa[++cnt]={z,3,i};
		}
		if(n>=200){
			
		
		
		unordered_map<int,int>mp;
		sort(aa+1,aa+cnt+1);
		if(f){
			int ans=0;
			for(int i=1;i<=n;i++)
				ans+=aa[i].a;
			printf("%d\n",ans);
			continue;
		}
		int ans=0;
		int tmp=0;
		for(int i=1;i<=cnt;i++){
			if(!vis[aa[i].id]&&mp[aa[i].op]<(n>>1)){
				vis[aa[i].id]=true;
				tmp++;
				ans+=aa[i].a;
				mp[aa[i].op]++;
			}
			if(tmp==n)
				break;
		}
		printf("%d\n",ans);
		continue;
	}
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}
