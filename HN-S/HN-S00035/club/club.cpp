#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
struct node{
	int x,id;
}p[4][maxn],a[maxn][5];
bool v[maxn],vis[maxn];
int n,f[maxn],cnt[4]={0,0,0,0};
int res[][4]={{0,1,2,3},
			  {0,1,3,2},
			  {0,2,1,3},
			  {0,2,3,1},
			  {0,3,1,2},
			  {0,3,2,1}};
bool cmp(node s,node t){
	return s.x>t.x;
}
int solve1(int k){
	memset(v,0,sizeof(v));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i){
		f[i]=1;p[1][i]=p[2][i]=p[3][i]={0,0};
	}
	int ans=0;
	for(int j=1;j<=3;++j){
		for(int i=1;i<=n;++i){
			if(a[i][f[i]].id==res[k][j]&&v[i]==0){
				p[res[k][j]][++cnt[res[k][j]]].x=a[i][f[i]].x;
				p[res[k][j]][cnt[res[k][j]]].id=i;
			}
		}
		sort(p[res[k][j]]+1,p[res[k][j]]+1+cnt[res[k][j]],cmp);
		for(int i=1;i<=n/2;++i){
			ans+=p[res[k][j]][i].x;
			v[p[res[k][j]][i].id]=1;
		}
		for(int i=n/2+1;i<=cnt[res[k][j]];++i){
			f[p[res[k][j]][i].id ]++;
		}
	}
	return ans;
} 
int solve2(int k){
	memset(v,0,sizeof(v));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i){
		f[i]=1;p[1][i]=p[2][i]=p[3][i]={0,0};
	}
	int ans=0;
	for(int j=1;j<=3;++j){
		for(int i=1;i<=n;++i){
				p[res[k][j]][++cnt[res[k][j]]].x=a[i][res[k][j]].x;
				p[res[k][j]][cnt[res[k][j]]].id=i;
		}
		sort(p[res[k][j]]+1,p[res[k][j]]+1+cnt[res[k][j]],cmp);
		for(int i=1;i<=n/2;++i){
			if(v[p[res[k][j]][i].id]==0){
				ans+=p[res[k][j]][i].x;
				v[p[res[k][j]][i].id]=1;
			}else{
				int e=1;
				while(v[p[res[k][j]][e+n/2].id]==1&&e<=n+1){
					e++;
				}
				ans+=p[res[k][j]][n/2+e].x;
				v[p[res[k][j]][n/2+e].id]=1;
			}
		}
		for(int i=n/2+1;i<=cnt[res[k][j]];++i){
			f[p[res[k][j]][i].id]++;
		}
	}
	return ans;
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
			a[i][1].id=1;
			a[i][2].id=2;
			a[i][3].id=3;
		}
		for(int i=1;i<=n;++i){
			sort(a[i]+1,a[i]+4,cmp);
		}
		int ans=0;
		for(int i=0;i<6;++i){
			ans=max(ans,max(solve1(i),solve2(i)));
		}
		cout<<ans<<endl;
	}
	return 0;
}
