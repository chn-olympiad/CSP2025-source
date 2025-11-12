/*#include <bits/stdc++.h>
using namespace std;
int t,n,ans;
int sw[100010];
struct fck{
	int u;
	int k;
	}a[100010][4];	
struct node{
	int v;
	int w;
	friend bool operator <(const node &a,const node &b){
		return a.w>b.w;
		}
	};
priority_queue <node> q[4];
bool cmp(fck a,fck b){
	return a.k>b.k;
	}	

void solve(int i,int s){
	if(i==1){
		ans+=a[i][s].k;
		q[a[i][s].u].push({i,a[i][s].k});
		sw[i]=s;
		return;
		}
	if(q[a[i][s].u].size()<n/2){
		ans+=a[i][s].k;
		q[a[i][s].u].push({i,a[i][s].k});
		sw[i]=s;
		return;
		}
	if(a[i][s+1].k+q[a[i][s].u].top().w<a[i][s].k+a[q[a[i][s].u].top().v][sw[q[a[i][s].u].top().v]+1].k){
		ans-=q[a[i][s].u].top().w;
		ans+=a[i][s].k;
		int p=q[a[i][s].u].top().v;
		q[s].pop();
		q[a[i][s].u].push({i,a[i][s].k});
		sw[i]=s;
		solve(p,sw[p]+1);
		return;
		}
	solve(i,s+1);		
	}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
//freopen("club1.in", "r", stdin);
//freopen("club.out", "w", stdout);	
cin>>t;
while(t--){
	memset(a,0,sizeof(a));
	//int sum[4]={0};
	ans=0;
	for(int i=1;i<=3;i++)
		while(!q[i].empty())
			q[i].pop();
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j].k;
			a[i][j].u=j;
			}
		sort(a[i]+1,a[i]+3+1,cmp);
		solve(i,1);
		}
	cout<<ans<<'\n';
	}
return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[100010][4];
int t1[100010];
void dfs(int i,int s1,int s2,int s3,int sum){
	if(i>n) {
		ans=max(ans,sum);
		return ;
		}
	if(s1<n/2) dfs(i+1,s1+1,s2,s3,sum+a[i][1]);
	if(s2<n/2) dfs(i+1,s1,s2+1,s3,sum+a[i][2]);
	if(s3<n/2) dfs(i+1,s1,s2,s3+1,sum+a[i][3]);
	}
int cmp(int a,int b){
	return a>b;
	}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
while(t--){
	ans=0;
	cin>>n;
	 for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
	if(n>=100){
	for(int i=1;i<=n;i++)
			t1[i]=a[i][1];
		sort(t1+1,t1+n+1,cmp);
		for(int i=1;i<=n/2;i++)
			ans+=t1[i];
		cout<<ans<<'\n';
		continue;
		}
	dfs(1,0,0,0,0);
	cout<<ans<<'\n';
	}
}
