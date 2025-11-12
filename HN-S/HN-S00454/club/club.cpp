#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,maxn,dp[205][105][105][105];
struct node{
	int l1,l2,l3;
}a[100005];
bool cmp1(node a,node b){return a.l1 > b.l1;}
bool cmp2(node a,node b){return a.l2 > b.l2;}
bool cmp3(node a,node b){return a.l3 > b.l3;}
bool cmp_(node a,node b){return abs(a.l1 - a.l2) > abs(b.l1 - b.l2);}
void dfs1(int step,int t2,int t3){
	if(step > n){
		ans = max(maxn,ans);
		return;
	}
	maxn += a[step].l2;
	dfs1(step + 1,t2 + 1,t3);
	maxn -= a[step].l2;
	maxn += a[step].l3;
	dfs1(step + 1,t2,t3 + 1);
	maxn -= a[step].l3;
}
void dfs2(int step,int t1,int t3){
	if(step > n){
		ans = max(maxn,ans);
		return;
	}
	maxn += a[step].l1;
	dfs2(step + 1,t1 + 1,t3);
	maxn -= a[step].l1;
	maxn += a[step].l3;
	dfs2(step + 1,t1,t3 + 1);
	maxn -= a[step].l3;
}
void dfs3(int step,int t1,int t2){
	if(step > n){
		ans = max(maxn,ans);
		return;
	}
	maxn += a[step].l1;
	dfs3(step + 1,t1 + 1,t2);
	maxn -= a[step].l1;
	maxn += a[step].l2;
	dfs3(step + 1,t1,t2 + 1);
	maxn -= a[step].l2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T --){
		ans = 0;
		maxn = 0;
		cin>>n;
		bool b = 0,b2 = 0;
		for(int i = 1; i <= n; i ++){
			cin>>a[i].l1>>a[i].l2>>a[i].l3;
			if(a[i].l2 != 0 || a[i].l3 != 0)b = 1;
			if(a[i].l3 != 0)b2 = 1;
		}
		if(!b2 && b){
			sort(a + 1,a + n + 1,cmp_);
			int t1 = 0,t2 = 0,id;
			for(int i = 1; i <= n; i ++){
				if(a[i].l1 > a[i].l2){
					t1 ++;
					ans += a[i].l1;
				}else{
					t2 ++;
					ans += a[i].l2;
				}
				if(t1 == n / 2 || t2 == n / 2){
					id = i + 1;
					break;
				}
			} 
			if(t1 == n / 2)for(int i = id; i <= n; i ++)ans += a[i].l2;
			if(t2 == n / 2)for(int i = id; i <= n; i ++)ans += a[i].l1;
			cout<<ans<<"\n";
			continue;
		}
		sort(a + 1,a + n + 1,cmp1);
		for(int i = 1; i <= n / 2; i ++)maxn += a[i].l1;
		if(!b){
			cout<<maxn<<"\n";
			continue;
		}
		dfs1(n / 2 + 1,0,0);
		maxn = 0;
		sort(a + 1,a + n + 1,cmp2);
		for(int i = 1; i <= n / 2; i ++)maxn += a[i].l2;
		dfs2(n / 2 + 1,0,0);
		maxn = 0;
		sort(a + 1,a + n + 1,cmp3);
		for(int i = 1; i <= n / 2; i ++)maxn += a[i].l3;
		dfs3(n / 2 + 1,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
