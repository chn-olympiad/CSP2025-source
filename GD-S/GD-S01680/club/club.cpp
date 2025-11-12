#include<bits/stdc++.h>
#define fo(i,n) for(int i=1;i<=n;i++)
#define ofo(i,n) for(int i=0;i<n;i++)
#define ll long long
#define endl "\n"
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fi first
#define se second
using namespace std;
const int N=100005;
int t,n,ans;
int a[N][3];
pair<int,int> best[N]; // first:man yi du; second:group
pair<int,int> mid[N];
inline void find_fise(int a1,int a2,int a3,int i){
	if(a1>=a2&&a1>=a3){ // best = a1
		best[i].fi=a1;
		best[i].se=0;
		if(a2>=a3){
			mid[i].fi=a2;
			mid[i].se=1;
		}
		else{
			mid[i].fi=a3;
			mid[i].se=2;
		}
	}
	else if(a2>=a1&&a2>=a3){ // best = a2
		best[i].fi=a2;
		best[i].se=1;
		if(a1>=a3){
			mid[i].fi=a1;
			mid[i].se=0;
		}
		else{
			mid[i].fi=a3;
			mid[i].se=2;
		}
	}
	else{ // best = a3
		best[i].fi=a3;
		best[i].se=2;
		if(a1>=a2){
			mid[i].fi=a1;
			mid[i].se=0;
		}
		else{
			mid[i].fi=a2;
			mid[i].se=1;
		}
	}
}
void dfs(int depth,int n,int cnt[],int sum){
	if(cnt[0]>n/2||cnt[1]>n/2||cnt[2]>n/2){
		return;
	}
	if(depth>n){
		ans=max(ans,sum);
	}
	int bf=best[depth].fi, bs=best[depth].se;
	int mf=mid[depth].fi, ms=mid[depth].se;
	cnt[bs]++;
	sum+=bf;
	dfs(depth+1,n,cnt,sum);
	cnt[bs]--;
	cnt[ms]++;
	sum-=bf;
	sum+=mf;
	dfs(depth+1,n,cnt,sum);
	cnt[ms]--;
	sum-=mf;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		ans=0;
		int cnt[3]={0,0,0};
		cin>>n;
		fo(i,n){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			find_fise(a[i][0],a[i][1],a[i][2],i);
		}
		dfs(1,n,cnt,0);
		cout<<ans<<endl;
	}
	return 0;
}
/*
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("club2.in","r",stdin);
//	freopen("club1.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(best,0,sizeof best);
		memset(mid,0,sizeof mid);
		priority_queue<pair<int,pair<int,int>>> q; // q:mid max
		cin>>n;
		int cnt[4]={0,0,0,0},sum=0;
		fo(i,n){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			find_fise(a[i][1],a[i][2],a[i][3],i);
			int bf=best[i].fi, bs=best[i].se;
			int mf=mid[i].fi, ms=mid[i].se;
			if(cnt[bs] < n/2){ // add best to group
				cnt[bs]++;
				sum+=bf;
				q.push({mid[i].fi,{mid[i].se,i}});
			}
			else{ // too many people
				int qfm=q.top().fi, qs=q.top().se.fi;
				int qfb=best[q.top().se.se].fi;
				if(qfb+mf>=qfm+bf){ // 新不如旧
					cnt[ms]++;
					sum+=mf;
				}
				else{ // 新人入队 旧人转队 
					cnt[qs]++;
					sum=sum-qfb+bf+qfm;
					q.pop();
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
*/
